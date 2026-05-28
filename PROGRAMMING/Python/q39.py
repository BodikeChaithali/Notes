a=3
b=4
l_1=[1,2]
l_2=l_1
l_1=l_1+[a]
print(l_1)
l_1=[b]+l_1
print(l_1,id(l_1)==id(l_2))
