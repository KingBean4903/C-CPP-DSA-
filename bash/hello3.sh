#!/bin/bash
echo -n "Hello I $(basename $0) may I ask your name: "
read
echo "Hello $REPLY"
exit 0
