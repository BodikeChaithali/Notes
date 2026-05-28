#!/bin/bash

words=$(grep -i "$2==A" CSP102.txt && grep -i "$2==B" CSP101.txt)
echo "$words"
