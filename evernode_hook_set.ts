import {
  Client,
  Wallet,
  Payment,
  SetHookFlags,
  TransactionMetadata,
} from '@transia/xrpl';
import {
  createHookPayload,
  setHooksV3,
  SetHookParams,
  Xrpld,
  ExecutionUtility,
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
    rl.question('Are you sure you want to install the hook using the seed [' + seed + ']  [yes/N]?', (answer) => {
        consent = answer;
        rl.close();
    });
    while (consent == "_") { await new Promise(r => setTimeout(r, 100))  }

    if(consent.toLowerCase() != 'yes')
    {
       console.log('BA BYE');
       process.exit(1);
    }

    //Edit seed to your Hook set account
    const myWallet = Wallet.fromSeed(seed);

    console.log("Creating hook payload...");
    const hookPayload = createHookPayload({version:0, createFile:'myhook', namespace:'myhook', flags:SetHookFlags.hsfOverride, hookOnArray:['Payment']});

    console.log("Generated hook payload:", hookPayload);

    try {
      console.log("Setting hook...");
      await setHooksV3({
        client: client,
        seed: myWallet.seed,
        hooks: [{ Hook: hookPayload }],
      } as SetHookParams);
      console.log("Hook set successfully.");
    } catch (error) {
      console.error("Error setting hook:", error);
    }


    await client.disconnect();
    console.log("Disconnected from server.");
  } catch (error) {
    console.error("Error occurred:", error);
  }
}

main();
