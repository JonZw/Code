import matplotlib.pyplot as plt
import math

coordinaten=[(0,0),(1,0),(0.5,math.sqrt(3)/2)]

def drittel(punkt1,punkt2):
    return (((punkt1[0]*2/3+punkt2[0]*1/3)),((punkt1[1]*2/3+punkt2[1]*1/3)))
def zrittel(punkt1,punkt2):
    return ((punkt1[0]*1/3+punkt2[0]*2/3),((punkt1[1]*1/3+punkt2[1]*2/3)))
def zacke(punkt1,punkt2):
    vector=((punkt2[0]-punkt1[0]),(punkt2[1]-punkt1[1]))
    vector=(vector[1],vector[0]*-1) # 90° gedreht
    mitte=(((punkt1[0]*1/2+punkt2[0]*1/2)),((punkt1[1]*1/2+punkt2[1]*1/2)))
    return ((mitte[0]+(vector[0]*0.28867513459)),(mitte[1]+(vector[1]*0.28867513459)))
            #wir gehen von der mitte den rechtwinkligen Vector (selbe länge wie
            #die gerade) 0.28(..=sqrt(1/3²-1/6²) also die höhe der Zacke) einheiten
            #entlang

def koch(punkte):
    i=0
    z=len(punkte)
    while z>0:
        punkt1=drittel(punkte[i],punkte[(i+1)%len(punkte)])
        punkt2=zacke(punkte[i],punkte[(i+1)%len(punkte)])
        punkt3=zrittel(punkte[i],punkte[(i+1)%len(punkte)])
        coordinaten.insert(i+1,punkt1)
        coordinaten.insert(i+2,punkt2)
        coordinaten.insert(i+3,punkt3)
        i=i+4
        z=z-1

def kochSnowflake(level):
    for _ in range(level):
        koch(coordinaten)
    return coordinaten

level=int(input("Wievile Schritte?\n"))
points=kochSnowflake(level)

plt.figure(figsize=(8, 8))
plt.axis('equal')
x = [i[0] for i in points]
y = [i[1] for i in points]
plt.fill(x,y)
plt.show()
