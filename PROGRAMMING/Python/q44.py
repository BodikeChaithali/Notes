def second(list_a):
    l=len(list_a)
    r=""
    for i in range(l):
        r+=list_a[i][1]
    return r

fruits=["apple","banana","pineapple"]
print(second(fruits).upper())
