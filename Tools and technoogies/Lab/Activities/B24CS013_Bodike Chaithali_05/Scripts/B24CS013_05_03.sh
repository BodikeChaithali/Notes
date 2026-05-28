#!/bin/bash

read -p "Enter a URl: " url
regex="^https?:\/\/[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}.*$"

if [[ $url =~ $regex ]]; then
	status=$(curl -s -o /dev/null -w "%{http_code}" -L "$url")
	if [[ $status =~ ^2[0-9]{2}$ ]]; then
		echo "Valid and reachable link."
	else
		echo "Link format valid but unreachable."
	fi
else
	echo "Invaid link format."
fi
