import math


def praesie():
    z0 = math.log(6)-math.log(5)
    print(z0)
    zn=z0
    for x in range(7):
        zn=(1/(x+1))-5*(zn)
        print(zn)


def rd(zahl):
    szahl = str(zahl)
    koma = False
    null = 0
    count=0
    while count < len(szahl):
        c=szahl[count]
        if c != '.' and c != '0':
            break
        szahl = szahl[:count] + szahl[count+1:]
        null+=1
        count-=1
        print(szahl)
        count+=1

    szahl=szahl[:3+null-2]
    if null>0:

        for x in range(null-2):
            szahl= "0"+szahl
        szahl = "0."+szahl

    zahl=szahl
    print("!",zahl)


praesie()
rd(0.000232344)
