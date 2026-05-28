#!/bin/bash

read -p "Enter any number: " num
fact=1
echo -n "$num!="
while ((num>0));
do
	fact=$((fact*num))
	num=$((num-1))
done
echo "$fact"
