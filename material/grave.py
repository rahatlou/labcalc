GRAV = 9.81

h = float(input("altezza h (m): "))
dt = float(input("passo dt (s): "))
t = 0.
y = h
print("   t\t   y")
while y > 0.:
    y = h - 0.5 * GRAV * t * t
    print("%6.2f\t%6.2f" % (t, y))
    t += dt
