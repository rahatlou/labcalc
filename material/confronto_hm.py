import numpy as np
import matplotlib.pyplot as plt

xp, yp = np.loadtxt('polare.txt', unpack=True)
xr, yr = np.loadtxt('cerchio.txt', unpack=True)

fig, (a, b) = plt.subplots(1, 2, figsize=(9, 4.4))
a.scatter(xp, yp, s=5, color='tab:red')
a.set_title('raggio e angolo uniformi')
a.set_aspect('equal')
b.scatter(xr, yr, s=5, color='tab:green')
b.set_title('metodo del rigetto')
b.set_aspect('equal')
plt.savefig('confronto.png')
plt.show()
