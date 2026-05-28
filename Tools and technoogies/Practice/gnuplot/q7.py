import matplotlib.pyplot as plt
x=[0,1,2,3,4,5]
y=[0,1,4,9,16,25]
z=[0,0,1,1,2,2]
plt.scatter(x,y,s=30,color="magenta",marker="*")
plt.scatter(x,z,s=30,color="blue",marker='o')
plt.show()
