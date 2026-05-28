sum=0
for i in range(1,4):
    for j in range(1,4):
        if i % j !=0:
            sum+=1
print(sum)

res=1
for i in range(5):
    for j in range(4,6):
        if i<j:
            res+=1
print(res)

c1=0
c2=14

for i in range(4,6):
    for j in range(i):
        c1+=1
    c2-=1
print("Count2: "+str(c2))
print("Count1: "+str(c1))
