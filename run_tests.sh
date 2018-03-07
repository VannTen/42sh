#!/bin/bash
SHELL="./42sh"

if [ -z "$1" ]
then
	echo 'usage: serial_tester.sh [ directory ]'
	exit 1
fi

while [ ! -f $SHELL ]
do
	read -p './42sh does not exist, please input path to shell:' SHELL
done

if [ -d "$1" ]
then
	for	testfile in "$1"/*.test
	do
		echo 'testfile:' $testfile
		cat $testfile
		echo 'vvvvvvvvvv Result vvvvvvvvvv'
		./42sh < $testfile
		echo ============================
	done
elif [ -e "$1" ]
then
	echo "$1: Not a directory."
else
	echo "$1: Not found."
fi
