num1=4
num2=10
c=0

for i in range(num1+1,num2):
    is_prime=True
    for j in range(2,i):
        if i % j == 0:
            is_prime=False
            break
    if is_prime:
        c=c+1
print(c)
