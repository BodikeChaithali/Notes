n=int(input())

for i in range(1,4):
    k=n-1
    while(k>=0):
        spaces=" "*k
        stars="* "*(i-1)+"* "
        k=k-1
    print(spaces+stars)
