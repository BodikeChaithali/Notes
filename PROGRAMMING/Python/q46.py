def is_same(l1,l2):
    if(id(l1)==id(l2)):
        print("id's are same")
    else:
        print("id's are different")

n1=input().split()
n2=input().split()
print(n1)
print(n2)
is_same(n1,n2)
