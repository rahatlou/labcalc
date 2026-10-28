dati = [1.5, 3.2, 2.8, 4.1, 3.7, 2.2]
print(len(dati), dati[0], dati[-1])
dati.append(5.0)
somma = 0.
for v in dati:
    somma += v
print("somma = %.1f" % somma)
print("media = %.3f" % (somma / len(dati)))
print(dati[:3])
