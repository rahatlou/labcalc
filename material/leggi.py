import numpy as np

# prima colonna in t, seconda in y
t, y = np.loadtxt('grave.txt', unpack=True)

print("righe lette: %d" % len(t))
print("t[0] = %.2f  y[-1] = %.2f" % (t[0], y[-1]))
