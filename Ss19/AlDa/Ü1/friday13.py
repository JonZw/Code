# es giebt 14 verschiedene moeglichkeiten:
# -der 1.1 ist ein Montag-Sontag -> 7 moeglichkeiten
# *2 weil es ein Schaltjahr sein kann
import time

def friday13():
    monate=[31,28,31,30,31,30,31,31,30,31,30,31]
    tage=["Montag","Dienstag","Mitwoch","Donnerstag","Freitag","Samstag","Sonntag"]
    counter=0
    print ("Das Jahr faengt an mit einem:")
    for wochentage in range(7):     # die sieben moeglichekeiten mit welche
        print ("\t"+tage[wochentage]+":")       #wochentag das jahr anfangen kann
        for nMonat in range(12):
            for tag in range(1,monate[nMonat]+1):
                if(wochentage==4 and tag==13):  #4 ist Freitag
                    print ("\t\t"+str(nMonat+1))
                    counter+=1
                wochentage+=1
                wochentage=wochentage%7

    print("\n\nSchaltjahre:\n")
    print ("Das Jahr faengt an mit einem:")
    monate[1]=29
    for wochentage in range(7):
        print ("\t"+tage[wochentage]+":")
        for nMonat in range(12):
            for tag in range(1,monate[nMonat]+1):
                if(wochentage==4 and tag==13):
                    print ("\t\t"+str(nMonat+1))
                    counter+=1
                wochentage+=1
                wochentage=wochentage%7

    print ("insgesamt "+str(counter)+" verschiedene 13. Freitage")

def friday13Since(day,month,year):
    monate=[31,28,31,30,31,30,31,31,30,31,30,31]
    wochentag=int(time.strftime("%w"))-1
    tag=int(time.strftime("%d"))
    nMonat=int(time.strftime("%m"))-1
    nyear=int(time.strftime("%y"))+2000
    monatspeicher=monate[nMonat]
    monate[nMonat]=tag
    anzahlMonate=nMonat
    end=False
    count=0
    for cJahr in range(nyear,year-1,-1):
        if cJahr%4==0 and (cJahr%100!=0 or cJahr%400==0):
            monate[1]=29
        else:
            monate[1]=28
        for cMonat in range(anzahlMonate,-1,-1):
            for cTag in range(monate[cMonat],0,-1):
                if wochentag==4 and cTag==13:
                    count+=1
                    print (str(cTag)+"."+str(cMonat+1)+"."+str(cJahr))
                wochentag=(wochentag-1)%7
                if(cTag==day and cMonat==month-1 and cJahr==year):
                    end=True
                if(end==True):
                    break
            monate[nMonat]=monatspeicher;
            if(end==True):
                break
        anzahlMonate=11

    print(count)
