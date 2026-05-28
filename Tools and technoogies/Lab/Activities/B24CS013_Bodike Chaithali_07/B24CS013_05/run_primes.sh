#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <n>"
    exit 1
fi

n=$1

gcc -o prime prime.c

for ((i=1; i<=n; i++))
do
    output=$(./prime $i)
    if [ ! -z "$output" ]; then
        echo "$output"
    fi
done

