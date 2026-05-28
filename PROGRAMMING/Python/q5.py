x=int(input())
n=int(input())
sum=x 
currSum=0
for i in range(n):
    currSum+=sum
    sum=sum*10+x
print(currSum) //245490735981226471715