import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 400)

f1 = np.sin(x)
f2 = np.cos(x)
f3 = np.exp(-0.1 * x**2) * np.sin(2 * x)
f4 = x * np.sin(x)

fig, axs = plt.subplots(2, 2, figsize=(10, 8))

plt.rcParams['font.family'] = 'Times New Roman'

axs[0, 0].plot(x, f1, color='blue')
axs[0, 0].set_title("f₁(x) = sin(x)", fontsize=12)
axs[0, 0].grid(True)

axs[0, 1].plot(x, f2, color='red')
axs[0, 1].set_title("f₂(x) = cos(x)", fontsize=12)
axs[0, 1].grid(True)

axs[1, 0].plot(x, f3, color='green')
axs[1, 0].set_title("f₃(x) = e^(-0.1x²) · sin(2x)", fontsize=12)
axs[1, 0].grid(True)

axs[1, 1].plot(x, f4, color='purple')
axs[1, 1].set_title("f₄(x) = x · sin(x)", fontsize=12)
axs[1, 1].grid(True)

fig.suptitle("Subplot of Four Mathematical Functions", fontsize=14, fontweight='bold')

plt.tight_layout(rect=[0, 0, 1, 0.95])
plt.savefig("multiplot.pdf")
plt.close()
