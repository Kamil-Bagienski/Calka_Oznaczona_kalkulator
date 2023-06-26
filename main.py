import matplotlib.pyplot as plt
import numpy as np

print("Obliczanie całki oznaczonej metodą trapezów")
print("na podstawie funkcji f(x) = ax^2 + bx + c")
poczatek = int(input("Podaj poczatek przedzialu: "))
koniec = int(input("Podaj koniec przedzialu: "))
a = float(input("Podaj a: "))
b = float(input("Podaj b: "))
c = float(input("Podaj c: "))
tablica = []

def pola_czastkowe(a, b, c, poczatek, koniec, tablica):
    for i in range(poczatek, koniec + 1):
        if(i > 0):
            tablica.append((a * (i * i)) + (b * i) + c)

def metoda_numeryczna(a, b, c, poczatek, koniec, tablica):
    suma = 0.0
    pola_czastkowe(a, b, c, poczatek, koniec, tablica)
    for i in range(0, koniec - poczatek):
        suma += ((tablica[i] + tablica[i+1]) / 2)
    return suma

print("Calka z przedziału od " + str(poczatek) + " do " + str(koniec) + " z funkcji f(x)=" + str(a) + "x^2+" + str(b) + "x+" + str(c) + " wynosi w przybliżeniu: " + str(metoda_numeryczna(a, b, c, poczatek, koniec, tablica)))

def metoda_dokladna(a, b, c, poczatek, koniec):
    return (((a * (koniec ** 3)) / 3) + ((b * (koniec ** 2)) / 2) + c * koniec) - (((a * (poczatek ** 3)) / 3) + ((b * (poczatek ** 2)) / 2) + c * poczatek)

print("Calka z przedziału od " + str(poczatek) + " do " + str(koniec) + " z funkcji f(x)=" + str(a) + "x^2+" + str(b) + "x+" + str(c) + " wynosi w przybliżeniu: " + str(metoda_dokladna(a, b, c, poczatek, koniec)))

def blad(a, b, c, poczatek, koniec, tablica):
    blad_bezwgledny = 0.0
    if(metoda_numeryczna(a, b, c, poczatek, koniec, tablica) > metoda_dokladna(a, b, c, poczatek, koniec)):
        blad_bezwgledny = metoda_numeryczna(a, b, c, poczatek, koniec, tablica) - metoda_dokladna(a, b, c, poczatek, koniec)
    else:
        blad_bezwgledny = metoda_dokladna(a, b, c, poczatek, koniec) - metoda_numeryczna(a, b, c, poczatek, koniec, tablica)
    blad_wzgledny = (blad_bezwgledny / metoda_dokladna(a, b, c, poczatek, koniec)) * 100
    print("Błąd bezwględny wynosi w przybliżeniu: " + str(blad_bezwgledny))
    print("Błąd względny wynosi w przybliżeniu: " + str(blad_wzgledny) + "%")

blad(a, b, c, poczatek, koniec, tablica)

x = np.linspace(poczatek, koniec, 100)
y = a * x**2 + b * x + c

plt.plot(x, y, label='f(x)='+str(a)+'x^2+'+str(b)+'x+'+str(c))
plt.fill_between(x, y, where=[poczatek <= xi <= koniec for xi in x], alpha=0.3)

plt.xlabel('x')
plt.ylabel('f(x)')
plt.title('Wykres funkcji f(x)='+str(a)+'x^2+'+str(b)+'x+'+str(c))

plt.legend()
plt.grid(True)
plt.show()
