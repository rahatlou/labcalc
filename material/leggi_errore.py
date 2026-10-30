import numpy as np

# stesso programma, ma su un file con testo dentro
t, y = np.loadtxt('grave_errato.txt', unpack=True)

print("righe lette: %d" % len(t))
