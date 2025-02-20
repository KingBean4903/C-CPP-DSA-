#!/bin/bash
if [ $# -lt 1 ] ; then
read -p "Enter your name: "
name=$REPLY
else
name=$1
fi
echo "Hello $name"
exit 0
