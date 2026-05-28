#!/bin/bash

if [[ $# == 2 ]]; then
	let sum=$1+$2
	echo "sum: $sum"
elif [[ $? != 0 ]]; then
	echo "Please provide valid integer numbers"
else
	echo "Please provide exactly 2 arguments"
fi
