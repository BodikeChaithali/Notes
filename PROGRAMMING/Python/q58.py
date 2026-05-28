def is_equal(a=122,b="B"):
    if a==ord(b):
        return True
    else:
        return False
i=122
a="V"
res=is_equal()
#print(res)
def pattern(var1=1):
    s=var1*"# "
    s=s.strip(" ")
    return s
#print(pattern(var1=2))
def p(n):
    b=n.split('.')
    return b
n="1.2.3.4.5"
#print(p(n))
def getid(l=[]):
    return id(l)
e=[4,8,10]
v1=getid(e)
v2=id(e)
#print(v1!=v2)
def ml(l):
    l=l+[sum(l)]
    return l
l1=[1.5,2,0.25,4,1]
m=ml(l1)
#print(id(l1)!=id(m))
def h(w1,w2):
    s1=sorted(w1)
    s2=sorted(w2)
    s1=''.join(s1)
    s2=''.join(s2)
    if s1==s2:
        return True
    return False
w1="cat"
w2="tac"
o=h(w1,w2)
#print(o)
l=[3,5,6,4]
n=l[1:4:-1]
for i in l:
    n+=[i**2]
print(sorted(n,reverse=True))
