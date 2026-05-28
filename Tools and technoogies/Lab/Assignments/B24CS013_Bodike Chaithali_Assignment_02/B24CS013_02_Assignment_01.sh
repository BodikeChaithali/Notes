#!/bin/bash

ACCOUNTS="Account.txt"
CREDENTIALS="Credentials.txt"

welcome_screen() {
	echo "**** Welcome to My shellATM ****"
	echo "**** Press any key to continue ****"
	read
}

authenticate_user() {
	while true; do
		echo "------------Login------------"
		read -p "Enter Card Number: " card
		read -p "Enter Password: " pass
		echo ""
		if grep -q "^$card,$pass$" "$CREDENTIALS"; then
			echo "Login successful!"
			return 0
		else
			echo "Invalid credentials. Try again."
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

withdraw_cash() {
	read -p "Enter amount to withdraw: " amt
	if [[ ! $amt =~ ^[0-9]+$ ]]; then
		echo "Invalid amount!"
		return
	fi
	balance=$(get_balance)
	if [[ amt > balance ]]; then
		echo "Insufficient balance!"
	else
		new_balance=$((balance - amt))
		update_balance "$new_balance"
		echo "Withdrawal successful. New Balance: $new_balance"
	fi
}

deposit_cash() {
	read -p "Enter amount to deposit: " amt
	if [[ ! $amt =~ ^[0-9]+$ ]]; then
		echo "Invalid amount!"
		return
	fi
	balance=$(get_balance)
	new_balance=$((balance + amt))
	update_balance "$new_balance"
	echo "Deposit successful. New Balance: $new_balance"
}

change_email() {
	read -p "Enter new email: " email
	if [[ $email =~ ^[a-zA-Z][a-zA-Z0-9._]*@[a-z]+(\.[a-z]+)+$ ]]; then
		sed -i "s/^\([^,]*,$card,\)[^,]*,\(.*\)/\1$email,\2/" "$ACCOUNTS"
		echo "Email updated successfully."
	else
		echo "Invalid email format!"
	fi
}

menu() {
	while true; do
		echo "1. Withdraw cash"
		echo "2. Deposit cash"
		echo "3. Settings"
		echo "4. Exit"
		read -p "Choose option: " opt
		case $opt in
			1) withdraw_cash ;;
			2) deposit_cash ;;
			3) change_email ;;
			4) exit ;;
			*) echo "Invalid choice" ;;
		esac
	done
}

main(){
	while true; do
		welcome_screen
		authenticate_user
		menu
	done
}

main
