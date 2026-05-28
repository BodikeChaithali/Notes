#!/bin/bash

fileName="$1"
sed -i 's/:/,/g' << "$1"
