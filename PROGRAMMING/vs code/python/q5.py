year=int(input("Enter an year:"))
if((year%4==0) and (not(year%100)==0) or (year%400==0)):
    print(f"{year} is leap year")
else :
    print(f"{year} common year")