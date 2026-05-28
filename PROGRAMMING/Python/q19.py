pattern=""

for i in range(1,3):
    pattern=""
    for j in range(1,i+1):
        if j == i:
            pattern+=str(j)
        else:
            pattern+=str(j)+" "
    print(pattern)
