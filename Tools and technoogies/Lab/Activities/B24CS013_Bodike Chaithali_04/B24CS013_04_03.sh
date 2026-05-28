#!/bin/bash
let n=5
for((i=1;i<=n;i++)); do
	for((j=1;j<=i;j++)); do
		echo -n "$j "
	done
	for((k=1;k<=(n-i)*2;k++)); do
		echo -n "  "
	done
	for((a=i;a>0;a--)); do
		echo -n "$a "
	done
	echo
done
for((i=n-1;i>0;i--)); do
	for((j=1;j<=i;j++)); do
		echo -n "$j "
	done
	for((k=1;k<=(n-i)*2;k++)); do
		echo -n "  "
	done
	for((a=i;a>0;a--)); do
		echo -n "$a "
	done
	echo
done
