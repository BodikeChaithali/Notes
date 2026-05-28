t1=1
t2=0

for i in range(4,6):
    j=6
    while(j<8):
        if i<j:
            t2+=1
        else:
            t1+=1
        j+=1
print(t2)
print(t1)
