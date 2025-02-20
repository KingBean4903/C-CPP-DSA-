#!/bin/bash
#AUTHOR: @shebang
#X: @shebang
#Script to backup files to a loction
read -p "Which file types do you want to backup: " file_suffix
read -p "Which directory do you want to backup to: " dir_name
test -d $HOME/$dir_name || mkdir -m 700 $HOME/$dir_name
find $HOME -path $HOME/$dir_name -prune -o \
-name "*$file_suffix" -exec cp {} $HOME/$dir_name/ \;
exit 0

