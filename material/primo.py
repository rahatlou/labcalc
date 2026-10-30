import matplotlib.pyplot as plt
import numpy as np

t, y = np.loadtxt('grave.txt', unpack=True)
plt.plot(t, y)
plt.show()
