def fin1(i,j):
    if i<=0:
        return j
    else:
        return fin1(j+1,i-j)

res=fin1(8,9)
#print(res)
#def f2(a):
#    if type(a)==type(1):
 #       print("Type int")
#def f1(la):
#    for i in la:
 #       if i.endswith('7'):
  #          f2(i)
#la=['47','85',chr(55),"5.7",chr(53),"56","Seven",str(ord("a"))]
#f1(la)
def gr(x,y):
    if is_true(x,y):
        print("True")
    else:
        print("False")
x=6
y=5
#gr(x,y)
def is_true(x,y):
    z=(x//y)==(x%y)
    return z
def f(mylist):
    fl=[]
    for el in mylist:
        if type(el)==type([]):
            fl+=f(el)
        else:
            fl+=el
    return fl
print(f(['p',['q',['r','s'],'t']]))
