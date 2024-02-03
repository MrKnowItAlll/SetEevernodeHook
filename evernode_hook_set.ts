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

export async function main(): Promise<void> {
  try {
    const serverUrl = 'wss://xahau.network';
    const client = new Client(serverUrl);
    await client.connect();
    client.networkID = await client.getNetworkID();

    //Edit seed to your Hook set account
    const myWallet = Wallet.fromSeed('');
    

    console.log("Creating hook payload...");
    const hookPayload = createHookPayload({version:0, createFile:'redirect', namespace:'redirect', flags:SetHookFlags.hsfOverride, hookOnArray:['Payment']});

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
