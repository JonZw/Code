def sieve(max):
    list = []
    for x in range(0,max+1):
        list.append(x)
    for y in range(2,(max/2)+1):
        for x in range(2,(max/2)+1):
            if x*y<max+1:
                list[x*y]=0
    list.remove(1)
    for x in range(list.count(0)):
        list.remove(0)
    return list
