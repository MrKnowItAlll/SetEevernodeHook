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

## Compile hook(Hook only needs to be compiled once, then same hook can be set on all hosts if you have more than 1)

    c2wasm-cli redirect.c build/

## Set copiled hook onto host account insert host seed

Run:

    ts-node evernode_hook_set.ts

example output:
    Please input your Desired destination account to forward EVR to:rDiNoBVMnYNqwUKFCUKmXWEg6a7RvWWkYT
    Detination Account to send EVR to:rDiNoBVMnYNqwUKFCUKmXWEg6a7RvWWkYT
    Please input your Host secret[seed]:sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo
    Are you sure you want to install the hook using the seed [sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo]  [yes/N]?yes
    ...
    ...
    ...
    Hook set successfully.


## If you wish to remove all hooks installed on the host account

Run:

    ts-node clear_all_hooks.ts

example output:

    Please input your Host secret[seed]:sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo
    Are you sure you want to remove all hooks using the seed [sEdVncdZZoZ2BjYFVPmfvC2FmecXDJo]  [yes/N]?yes
    Removing Hooks...
    Disconnected from server.
