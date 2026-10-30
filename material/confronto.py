import matplotlib.pyplot as plt
import numpy as np

GRAV = 9.81
h = 20.

t, y = np.loadtxt('grave.txt', unpack=True)

# 100 tempi tra 0 e 2.2
tt = np.linspace(0., 2.2, 100)
yy = h - 0.5 * GRAV * tt**2     # formula su tutto l'array

plt.plot(tt, yy, '-', color='gray', label='formula')
plt.plot(t, y, 'o', color='teal', label='dati')
plt.axhline(y=0., color='red', linestyle='--')
plt.xlabel('tempo (s)')
plt.ylabel('quota (m)')
plt.legend()
plt.show()
