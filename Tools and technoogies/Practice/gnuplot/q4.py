import matplotlib.pyplot as plt
x=[1,2,3,4,5,6]
y=[1,4,9,16,25,36]
plt.plot(x,y,color="green",linestyle="dashed",linewidth=3,marker='o',markerfacecolor="blue",markersize=12)
plt.ylim(1,40)
plt.xlim(1,10)
plt.xlabel("Numbers")
plt.ylabel("Squares of the numbers")
plt.title("Line Plot with Customization")
plt.show()
