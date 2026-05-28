m="SuMM3r SeAs0n"
c1=0
c2=0
c3=0
for ch in m:
    if ch.isdigit():
        continue
    if ord(ch)>=65 and ord(ch)<=90:
        c2+=1
    elif ord(ch)>=97 and ord(ch)<=122:
        c1+=1
    else:
        c3+=1
print("No of lower case letters - "+str(c1))
