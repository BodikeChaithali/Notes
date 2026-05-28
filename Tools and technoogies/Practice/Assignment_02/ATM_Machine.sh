#!/bin/bash
ACCOUNTS=Accounts.txt

greetings() {
	echo "**** Welcome to My shellATM ****"
	echo "**** Press any key to continue ****"
	read 
}

seekthecredentials() {
	while true; do
		echo "********Login********"
		read -p "Enter Card Number: " card
		read -p "Enter password: " pass
		if grep -q "^$card,$pass$" "Credentials.txt"; then
			echo "Login Successfull!"
			return 0
		else
			echo "Invalid details.Try again..."
		fi
	done
}

get_balance() {
       grep -E "^.*$card.*" "$ACCOUNTS" | awk -F',' '{print $4}'
}

update_balance() {
	new_balance=$1
	sed -i "s/^\([^,]*,$card,[^,]*,\)[0-9]\+/\1$new_balance/" "$ACCOUNTS" 
}

Withdraw_cash() {
	read -p "Enter amount to withdraw: " amount
	if [[ ! $amount =~ ^[0-9]+$ ]]; then
		echo "Inavild amount!!"
		return
	fi
	balance=$(get_balance)
	if [[ $amount -gt $balance ]];then
		echo "Insufficient balance"
	else
		new_balance=$((balance - amount))
		update_balance "$new_balance"
		echo "Withdrawl succesfull.New balance: $new_balance"
	fi
}

Deposite_cash() {
	read -p "Enter the amount: " amt
	if [[ ! $amt =~ ^[0-9]+$ ]];then
		echo "Invalid amount!!"
		return
	fi
	balance=$(get_balance)
	new_balance=$((balance+amt))
	update_balance "$new_balance"
	echo "Deposited succesfully. New Balance: $new_balance"
}

Change_email() {
	read -p "Enter new email: " email
	if [[ $email =~ ^[a-zA-Z][a-zA-Z0-9._]@[a-z]+(\.[a-z]+)+$ ]];then
		sed -i "s/^\([^,]*,$card,\)[^,]*,\(.*\)/\1$email,\2/" "$ACCOUNTS"
		echo "Email updated successfully!!"
	else
		echo "Invalid email format!!"
	fi
}

menu() {
	while true;do
		echo "1.Withdraw Cash"
		echo "2.Deposit Cash"
		echo "3.Settings"
		echo "4.Exit"
		read -p "Enter your option: " op
		case $op in
			1) Withdraw_cash ;;
			2) Deposite_cash ;;
			3) Change_email ;;
			4) exit ;;
			*) echo "Invalid choice!!"
		esac
	done
}

main() {
	while true; do
		greetings
		seekthecredentials
		menu
	done
}

main
