#!/bin/bash

read -p "Enter the choice(1-4): " n
case $n in
	1)
		echo "1"
		;;
	2)
		echo "2"
		;&
	3)
		echo "3"
		;;
	4)
		echo "4"
		;;
	*)
		echo "Default"
		;;
esac
