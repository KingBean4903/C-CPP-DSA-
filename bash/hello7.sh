#!/bin/bash
read -p "Enter your name autobot: " name
echo "Welcome back $name"
read -sn5 -p "Enter your password" password
echo "Authenticated successfully"
read -sn1 -p "Good by $name $password"
echo
exit 0
