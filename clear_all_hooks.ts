import {
  Client,
  Wallet,
} from '@transia/xrpl';
import {
  clearAllHooksV3,
  SetHookParams,
} from '@transia/hooks-toolkit';

import * as xrpl from 'xrpl';
import * as readline from "readline";

export async function main(): Promise<void> {
  try {
    const serverUrl = 'wss://xahau.network';
    const client = new Client(serverUrl);
    await client.connect();
    client.networkID = await client.getNetworkID();

    const rl = readline.createInterface({
      input: process.stdin,
      output: process.stdout
    });

    let seed = "_"
    rl.question('Please input your Host secret[seed]:', (answer) => {
        seed = answer;
    });
    while (seed == "_") { await new Promise(r => setTimeout(r, 100))  }

    let consent = "_"
    rl.question('Are you sure you want to remove all hooks using the seed [' + seed + ']  [yes/N]?', (answer) => {
        consent = answer;
        rl.close();
    });
    while (consent == "_") { await new Promise(r => setTimeout(r, 100))  }

    if(consent.toLowerCase() != 'yes')
    {
       console.log('BA BYE');
       process.exit(1);
    }
    
    const myWallet = Wallet.fromSeed(seed);

    console.log("Removing Hooks...");

    try {
      await clearAllHooksV3({
        client: client,
        seed: myWallet.seed,
      } as SetHookParams)
    } catch (error) {
      console.error("Error Removing hooks:", error);
    }

    await client.disconnect();
    console.log("Disconnected from server.");
  } catch (error) {
    console.error("Error occurred:", error);
  }
}

main();
