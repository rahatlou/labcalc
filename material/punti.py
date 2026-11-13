import numpy as np
import matplotlib.pyplot as plt

x, y = np.loadtxt('punti.txt', unpack=True)
cx = 0
cy = 0
for i in range(len(x)):
    cx += x[i]
    cy += y[i]
cx /= len(x)
cy /= len(x)

plt.scatter(x, y, label='punti')
plt.scatter(cx, cy, color='red', marker='+', s=200, label='baricentro')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.savefig('punti.png')
plt.show()
