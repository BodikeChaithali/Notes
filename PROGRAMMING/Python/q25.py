for i in range(1,5):
    for j in range(1,i+1):
        if j == 1 or j == i or i==4:
            print(5-j,end=" ")
        else:
            print(" ",end=" ")
    print()
