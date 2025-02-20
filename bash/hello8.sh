#!/bin/bash
echo "You are usint $(basename $0)"
test -z $1 || echo "Autobots $1"
exit 0
