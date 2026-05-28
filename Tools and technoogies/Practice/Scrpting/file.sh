#!/bin/bash

output_file="files.txt"
if [ "$#" -ne 0 ]; then
	for fname in "$@"
	do
		if [ -f "$fname" ]; then
			cat "$fname" >> "$output_file"
		else
			echo "$fname does not exits or it is not a regular file"
		fi
	done
else
	echo "Please pass at least one file name"
fi
