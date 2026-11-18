import numpy as np
import matplotlib.pyplot as plt

t = np.loadtxt('arrivi.txt')
plt.hist(t, bins=30, range=(0, 30), density=True)
plt.xlabel('minuti')
plt.ylabel('densita')
plt.savefig('uniforme.png')
plt.show()
