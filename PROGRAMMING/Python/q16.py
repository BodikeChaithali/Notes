num=2

for i in range(0,num+1):
    text=""
    res=num-i
    for j in range(res):
        text=text+str(res)
    print(text)

i=1
while(i<5):
    for j in range(5,7):
        if j % i == 1:
            print(str(j)+" "+str(i))
    i=i+1
