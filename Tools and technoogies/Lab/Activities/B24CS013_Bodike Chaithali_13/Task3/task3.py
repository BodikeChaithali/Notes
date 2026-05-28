import matplotlib.pyplot as plt

male_heights = [150, 155, 160, 162, 165, 168, 170, 172, 175, 178]
male_weights = [50, 53, 55, 58, 60, 62, 65, 67, 70, 73]

female_heights = [148, 152, 157, 160, 163, 165, 168, 170, 173, 175]
female_weights = [48, 50, 53, 55, 58, 60, 62, 64, 67, 69]

plt.figure(figsize=(8, 6))

plt.scatter(male_heights, male_weights, color='blue', marker='*', s=100, label='Male')

plt.scatter(female_heights, female_weights, color='red', marker='o', s=80, label='Female')

plt.xlabel("Height (cm)", fontsize=12)
plt.ylabel("Weight (kg)", fontsize=12)
plt.title("Height vs Weight of Students by Group", fontsize=14, fontweight='bold')

plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()

plt.savefig("height_scatterplot.pdf")
plt.show()
