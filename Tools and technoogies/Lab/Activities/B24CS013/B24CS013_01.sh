#!/bin/bash

read -p "Enter an IP address: " ip
if [[ $ip =~ ^([0-9]{1,3}\.){3}[0-9]{1,3}$ ]]; then
        valid=1
        oldIFS=$IFS
        IFS='.'
        for octet in $ip
        do
                if (( octet < 0 || octet > 255 )); then
                        echo "Ivalid IP: one or more octets are out of range (0-255)."
                        valid=0
                        break
                fi
        done
        IFS=$oldIFS

        if (( $valid )); then
                echo "Valid IP address."
        fi
else
        echo "Invalid IP Format"
fi
