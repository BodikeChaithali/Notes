import matplotlib.pyplot as plt

subjects = ['Math', 'Science', 'English', 'History', 'Computer Science']
study_hours = [10, 8, 6, 4, 12]
colors = ['#ff9999', '#66b3ff', '#99ff99', '#ffcc99', '#c2c2f0']

explode = (0, 0, 0, 0, 0.1)

plt.figure(figsize=(12,6))

plt.pie(study_hours,labels=subjects,colors=colors,autopct = '%1.1f%%',startangle = 140,shadow=True,explode=explode,radius=1.1)

plt.title("Weekly Study Time Allocation",y=1.03,fontsize=14,fontweight='bold')
plt.legend(subjects,title="subjects",bbox_to_anchor=(1,0,0.5,1),loc="best")

plt.savefig("study_time_pie_chart.pdf")
plt.show()
