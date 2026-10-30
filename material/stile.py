import matplotlib.pyplot as plt
import numpy as np

t, y = np.loadtxt('grave.txt', unpack=True)

plt.plot(t, y, 'o', color='teal', label='caduta da 20 m')
plt.xlabel('tempo (s)')
plt.ylabel('quota (m)')
plt.title('Caduta di un grave')
plt.legend()
plt.grid()
plt.show()
