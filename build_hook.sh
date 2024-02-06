#! /bin/bash
echo Please insert your Xahau Destination address:

read rAddress

read -p "Are you sure [$rAddress] Destination is where you want to send your EVR to [y/N]? " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]
then
  echo Creating the hook with rAddress: $rAddress
  rm build/* > /dev/null 2>&1
  rm build/myhook.c > /dev/null 2>&1
  echo '#define XAH_FORWARD_ACT "'$rAddress'"' > build/myhook.c
  cat redirect.c >> build/myhook.c
  echo "Compiling hook"
  c2wasm-cli build/myhook.c build/
  echo "Done"
else
  echo "K Ba Bye"
fi
