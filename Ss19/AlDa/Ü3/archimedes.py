import math

def archimedes1(k):
    in_=math.sqrt(2)
    out_=2
    edges = 4
    outfromin_=2
    print(edges," Ecken:\n",(edges/2)*out_,"-",(edges/2)*in_,"=",(edges/2)*out_-(edges/2)*in_,out_==outfromin_,outfromin_)
    for x in range(k):
        in_=math.sqrt(2-math.sqrt(4-(in_**2)))
        out_=(2/out_)*(math.sqrt(4+(out_**2))-2)
        outfromin_=2*in_/(math.sqrt(4-(in_**2)))
        edges*=2
        print(edges," Ecken:\n",(edges/2)*out_,"-",(edges/2)*in_,"=",(edges/2)*out_-(edges/2)*in_,out_==outfromin_,outfromin_)

def archimedes2(k):
    in_=math.sqrt(2)
    out_=2
    outfromin_=2
    edges = 4
    print(edges," Ecken:\n",(edges/2)*out_,"-",(edges/2)*in_,"=",(edges/2)*out_-(edges/2)*in_,out_==outfromin_,(edges/2)*outfromin_)
    for x in range(k):
        in_=in_/(math.sqrt(2+math.sqrt(4-(in_**2))))
        out_=(2*out_)/(math.sqrt(4+(out_**2))+2)
        outfromin_=(2*in_)/(math.sqrt(4-(in_**2)))
        edges*=2
        print(edges," Ecken:\n",(edges/2)*out_,"-",(edges/2)*in_,"=",(edges/2)*out_-(edges/2)*in_,out_==outfromin_,(edges/2)*outfromin_)

archimedes1(14)

'''

    b)
    Bei 131072 Ecken wird die Differenz zwischen in und out negativ
    Diser Fehler kommt von einem Rundungsfehler bei der Subtraktion,
    Die sogenannte Auslöschung: ist der Subtrahend der Zahl zu ähnlich
    wird das Ergebnis auf 0 gerundet. Hier taucht das wegen dem minus in
    der Formel auf. Nehmen wir das minus raus kann keine Auslöschung mehr
    passieren

    c)
    a-b=(a²-b²)/(a+b)
    ->
        s(2n)=√(2-√(4-s(n)²))
             =√((4-(4-s(n)²)/(2+√(4-s(n)²))))
             =√(s(n)²/(2+√(4-s(n)²)))
             =√(s(n)²)/√(2+√(4-s(n)²))
             =s(n)/√(2+√(4-s(n)²))
                                        ❑
    ->
        t(2n)=(2/t(n))*(√(4+t(n)²)-2)
             =(2/t(n))*(((4+t(n)²)-4)/(√(4+t(n)²)+2))
             =(2/t(n))*(t(n)²/(√(4+t(n)²)+2))
             =(2*t(n)²)/((√(4+t(n)²)+2)*t(n))
             =2t(n)/(√(4+t(n)²)+2)
                                        ❑

    Die Neuen Formeln sind besser da sie weniger Subtraktionen zweier Zahlen haben
    die sich zu ähnlich sind und so Auslöschung hervorrufen

    ungefähr alle 3 verdopplungen bekommt man eine weitere richtige stelle von Pi
    also 1/3 stelle pro verdopplung

    d)
        Schon bei der 3 Verdopplung tritt ein fehler auf
'''
