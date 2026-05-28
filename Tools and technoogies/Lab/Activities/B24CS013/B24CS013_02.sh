#!/bin/bash

max() {
        arr=("$@")
        max=${arr[0]}
        for i in "${arr[@]}"; do
                if ((i > max)); then
                        max=$i
                fi
        done
        echo $max
}

main (){
        read -p "Enter no.of elements: " n
        arr=()
        for ((i=0;i<n;i++)); do
                read num
                arr+=($num)
        done
        max=$(max "${arr[@]}")
        echo "Maximum element: $max" 
}

main
