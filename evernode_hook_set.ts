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
  iHookParamEntry,
  iHookParamName,
  iHookParamValue,
  Xrpld,
  ExecutionUtility,
} from '@transia/hooks-toolkit';
import {
  xrpAddressToHex,
} from '@transia/hooks-toolkit/dist/npm/src/libs/binary-models'

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

    //Get Destination account
    let detinationAccount = "_"
    rl.question('Please input your Desired destination account to forward EVR to:', (answer) => {
        detinationAccount = answer;
    });
    while (detinationAccount == "_") { await new Promise(r => setTimeout(r, 100))  }

    let destinationID;
    try {
        destinationID = xrpAddressToHex(detinationAccount)
    } catch (error) {
      console.error("Cant decode Account ID from given destination rAddress, please make sure to use proper destination address", error);
      process.exit(1);
    }
    console.log('Detination Account to send EVR to:' + detinationAccount);

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
    
    const myWallet = Wallet.fromSeed(seed);

    console.log("Creating hook payload...");

    const hookparam = new iHookParamEntry(new iHookParamName('A'),new iHookParamValue(destinationID, true))
    const hookPayload = createHookPayload({version:0, createFile:'redirect', namespace:'redirect', flags:SetHookFlags.hsfOverride, hookOnArray:['Payment'], hookParams: [hookparam.toXrpl()],});

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
