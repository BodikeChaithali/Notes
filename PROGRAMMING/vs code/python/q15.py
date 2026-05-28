number=int(input("Enter the number:"))
i=1
sum=0
# First n numbers sum 
while(i<=number):
    sum=sum+i
    if(i<number):
        print(f"{i} + ",end="")
    else:
        print(f"{i} = ",end="")
    i+=1
print(sum)
# Factorial of an number 
product=1
i=number
while(i>0):
    product=product*i
    if(i>=2):
        print(f"{i} X ",end="")
    else:
        print(f"{i} = ",end="")
    i-=1
print(product)

