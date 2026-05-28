#!/bin/bash

if [[ $# != 0 ]]; then
	for fname in "$@"; do
		if [ -f "$fname" ]; then
			cat "$fname" >> "files.txt"
		else
			echo "$fname doesnot exits"
		fi
	done
else
	echo "please enter atleast one argument"
fi
