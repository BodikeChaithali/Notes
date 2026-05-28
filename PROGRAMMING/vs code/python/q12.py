n=int(input("Enter how many subjects you have:"))
Dict={}
for i in range(1,n+1):
    subName=input(f"Enter {i} subject name:")
    subMarks=int(input(f"Enter your {i} subject marks:"))
    Dict[subName] = subMarks  # Adding to dictionary
print(f"Your subject and marks in the form of Dict are \n {Dict}")
