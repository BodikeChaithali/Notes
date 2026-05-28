import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LinearSegmentedColormap

factories = [
    (8, 8, 100),
    (30, 10, 120),
    (20, 35, 90),
    (10, 25, 110),
    (35, 30, 80)
]

k = 0.1

def distance(x1, y1, x2, y2):
    return np.sqrt((x1 - x2)**2 + (y1 - y2)**2)

def pollution(x, y):
    total_pollution = np.zeros_like(x)
    for fx, fy, I in factories:
        d = distance(x, y, fx, fy)
        total_pollution += I * np.exp(-k * d)
    return total_pollution

N = 200
x = np.linspace(0, 40, N)
y = np.linspace(0, 40, N)
X, Y = np.meshgrid(x, y)
Z = pollution(X, Y)

colors = ['blue', 'cyan', 'green', 'yellow', 'red']
cmap = LinearSegmentedColormap.from_list('pollution_cmap', colors)

plt.figure(figsize=(30/2.54, 14/2.54))
plt.imshow(Z, origin='lower', extent=[0, 40, 0, 40], cmap=cmap, aspect='auto')

for fx, fy, _ in factories:
    plt.plot(fx, fy, 'o', markersize=12, color='black', zorder=3)
    plt.plot(fx, fy, 'o', markersize=8, color='red', zorder=4)
    plt.text(fx + 0.5, fy + 0.5, f'({fx},{fy})', color='black', fontsize=10, fontname='Times New Roman', zorder=5)

plt.xlabel('X coordinate(Units)', fontsize=14, fontname='Times New Roman')
plt.ylabel('Y coordinate(Units)', fontsize=14, fontname='Times New Roman')
plt.title('Pollution Heatmap of Industrial Zone', fontsize=16, fontname='Times New Roman')

cbar = plt.colorbar()
cbar.set_label('Pollution Intensity (arb. units)', fontsize=12, fontname='Times New Roman')

plt.tight_layout()
plt.savefig('factory_pollution.pdf', format='pdf')
plt.close()
