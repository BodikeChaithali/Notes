n=int(input())
k=int(input())
for i in range(n,0,-1):
    if n % i==0:
        k-=1
        if k==0:
            print(i)
            break