import numpy as np
import matplotlib.pyplot as plt

x, y = np.loadtxt('cerchio.txt', unpack=True)

plt.scatter(x, y, s=5)
plt.axis('equal')
plt.xlabel('x')
plt.ylabel('y')
plt.savefig('cerchio.png')
plt.show()
