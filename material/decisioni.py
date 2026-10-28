t = float(input("temperatura acqua (C): "))
if t <= 0:
    print("ghiaccio")
elif t < 100:
    print("liquida")
else:
    print("vapore")
if t <= 0 or t >= 100:
    print("non e liquida")
