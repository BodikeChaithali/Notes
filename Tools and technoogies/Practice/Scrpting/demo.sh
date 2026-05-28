print_array() {
    local arr=("$@")        # capture all arguments as an array
    for element in "${arr[@]}"; do
        echo "$element"
    done
}

fruits=("apple" "banana" "cherry")
print_array "${fruits[@]}"   # pass all elements

