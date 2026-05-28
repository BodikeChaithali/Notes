def prin(a,b,c):
    d=(b*b)-(4*a*c)
    if d>0:
        print("Roots are Real and unequal")
    elif d==0:
        print("Roots are Real and Equal")
    else:
        print("Roots are imaginary")

p=1
q=-5
r=6
prin(p,q,r)
