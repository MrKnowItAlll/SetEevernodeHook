# Description

Small hook to forrward host EVR rewards to a specific Xahau account.
Hook allows for EVR to be accepted by forwarded account, but will forward all EVR received to the destination account set in the Hook

## Setup

    git clone https://github.com/MrKnowItAlll/SetEevernodeHook.git
    cd SetEevernodeHook
    npm install 16
    npm use 16
    npm install
    npm i -g c2wasm-cli xrpld-cli
    npm install -g ts-node

## Adjust hook to your destination and compile

modify hook **redirect.c** rAddress:

    #define XAH_FORWARD_ACT ""

example

    #define XAH_FORWARD_ACT "rDiNoBVMnYNqwUKFCUKmXWEg6a7RvWWkYT"

**compile hook:**

    c2wasm-cli redirect.c build/

## Set copiled hook onto host account

modify set script **evernode_hook_set.ts** seed:

    const myWallet = Wallet.fromSeed('');


example

    const myWallet = Wallet.fromSeed('sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo');

**Then run the script to set it**

    ts-node evernode_hook_set.ts




