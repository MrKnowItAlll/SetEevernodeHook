# Description

Small hook to forrward host EVR rewards to a specific Xahau account.
Hook allows for EVR to be accepted by forwarded account, but will forward all EVR received to the destination account set in the Hook

Hook was developed by Transia, original hook:

https://github.com/Transia-RnD/xhs-library/tree/main/contracts/redirect

## Setup

    git clone https://github.com/MrKnowItAlll/SetEevernodeHook.git
    cd SetEevernodeHook
    nvm install 16
    nvm use 16
    npm install
    npm i -g c2wasm-cli xrpld-cli
    npm install -g ts-node

## Compile hook with your Destination Address to forward EVR to(Hook only needs to be compiled once, then same hook can be set on all hosts if you have more than 1)

    ./build_hook.sh

example output

    Please insert your Xahau Destination address:
    rDiNoBVMnYNqwUKFCUKmXWEg6a7RvWWkYT
    Are you sure [rDiNoBVMnYNqwUKFCUKmXWEg6a7RvWWkYT] Destination is where you want to send your EVR to [y/N]? y
    Creating the hook with rAddress: rDiNoBVMnYNqwUKFCUKmXWEg6a7RvWWkYT
    Compiling hook
    Done

## Set copiled hook onto host account insert host seed

Run:

    ts-node evernode_hook_set.ts

example output:

    Please input your Host secret[seed]:sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo
    Are you sure you want to install the hook using the seed [sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo]  [yes/N]?yes
    ...
    ...
    ...
    Hook set successfully.
