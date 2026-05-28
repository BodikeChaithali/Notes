a=3
l_a=[1,2]
l_b=l_a+[a]
print(id(l_a)==id(l_b))

l_a+=[4]
print(l_b)
