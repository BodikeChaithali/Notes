list=[1, 4, 9, 16, 25, 36, 49, 64, 81,100]
for i in range(1,len(list)) :
    print(f"{list[i]} ",end="")
print("")
number=int(input("Enter number to search:"))
if(number in list):
    print(f"{number} in this list")
else:
    print(f"{number} not in an given list you can see it {list}")