# x=int(input())
# n=int(input())
# sum=0
# for i in range(1,n+1):
#     sum+=x**(2*i-1)
# print(sum)
# x=int(input())
# n=int(input())
# sum=0
# for i in range(1,n+1):
#     sum+=x**(2*i)
# print(sum)
x=int(input())
n=int(input())
sum=0
for i in range(1,n+1):
    sum+=(x**(2*i))*(-1)**(i+1)
print(sum)