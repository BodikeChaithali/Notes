c=input()
t=0

for i in range(0,len(c)):
    for j in range(0,len(c)):
        if i==j:
            t=t+1
print(t)
