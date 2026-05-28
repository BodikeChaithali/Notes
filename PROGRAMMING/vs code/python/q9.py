list=[]
number=int(input("Enter how much will be the length of the list:"))
for i in range(1,number+1):
    listVariable=input("Enter number to add in the list: ")
    list.append(listVariable)
print(f"You entered list is {list} ")
listCopy=list.copy()
list.reverse()
print(f"Reversed list is {list}")
if(list == listCopy):
    print(f"{listCopy} is a palindrome list")
else:
    print(f"{listCopy} is not a palindrome list")