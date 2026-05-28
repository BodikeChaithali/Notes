import matplotlib.pyplot as plt
act=["eat","sleep","word","play"]
slices=[3,7,8,6]
color=['r','y','g','b']
plt.figure(figsize=(6,6))
plt.pie(slices,labels=act,colors=color,startangle=90,shadow=True,explode=(0,0,0.1,0),radius=1.2,autopct='%1.1f%%')
plt.legend()
plt.title("Daily Actiities Distribution")
plt.show()
