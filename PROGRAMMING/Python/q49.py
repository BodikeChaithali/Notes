w=input()
flag=False
for i in w:
    if (i==i.lower()) or (i=="_"):
        continue
    else:
        flag=True
        break
if flag==False:
    print("word is in snake_case")
else:
    print("nm,")
