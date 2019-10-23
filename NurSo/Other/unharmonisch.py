
def evilfour(number):
    strnumber=str(number)
    if "4" not in strnumber:
        return True
    else:
        return False


def inharmonic():
    summ = 0
    for n in range(1,10000000):
        if evilfour(n):
            #print(n)
            summ+=1/n
    print(summ)


inharmonic()
