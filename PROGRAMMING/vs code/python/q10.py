tuple=("C","D","A","A","B","B","A")
value=input("Enter a grade to count how many students as got it:")
if(value in tuple) :
    print(f"No.of time {value} is present in tuple is {tuple.count(value)}")
else :
    print(f"{value} is not present in the tuple {tuple}")
listCopy=list(tuple)
list=listCopy.copy()
list.sort()
print(f"list {listCopy} in asending order is {list}")
