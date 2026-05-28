# x=True
# y=True
# a = x or y
# b=x or y
# c=((not (a or b)) and (not(a and b)))
# print(c)
# a="Ballon"
# b="Ball"
# x=a[:4]==b[:4]
# y=a[2:5]!=b[2:7]
# z=a[:2]==b[:4]
# print((x or y)and z)
a=False
b=False
x=a==b
z=not b
y=a==z
print((not x)and y)