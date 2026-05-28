num=int(input("Enter any one number from 1,2 and 3:"))
D={
    1:"One",
    2:"Two",
    3:"Three"
}
if(num in D):
    print(f"{num} in words {D.get(num)}")
else:
    print("Invalid input")