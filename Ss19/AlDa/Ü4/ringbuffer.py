import copy
import timeit

class UniversalContainer1:
    def __init__(self):
        self.capacity_ = 1
        # constructor for empty container
        # we reserve memory for at least one item
        self.data_ = [None]*self.capacity_ # the internal memory
        self.size_ = 0
        # no item has been inserted yet
    def size(self):
        return self.size_
    def capacity(self):
        return self.capacity_
    def push(self, item):
    # add item at the end
        if self.capacity_ == self.size_: # internal memory is full
            self.data_.append(None)
            self.capacity_+=1
        self.data_[self.size_] = item
        self.size_ += 1
    def popFirst(self):
        if self.size_ == 0:
            raise RuntimeError("popFirst() on empty container")
        out=self.data_[0]
        for x in range(self.size_-1):
            self.data_[x]=self.data_[x+1]
        self.size_-=1
        return out
    def popLast(self):
        if self.size_ == 0:
            raise RuntimeError("popLast() on empty container")
        out=self.data_[self.size_-1]
        self.size_-=1
    def __getitem__(self, index):# __getitem__ implements v = c[index]
        if index < 0 or index >= self.size_:
            raise RuntimeError('index out of range')
        return self.data_[index]
    def __setitem__(self, index, v): # __setitem__ implements c[index] = v
        if index < 0 or index >= self.size_:
            raise RuntimeError("index out of range")
        self.data_[index]=v
    def first(self):
        return self.data_[0]
    def last(self):
        return self.data_[self.size_-1]

class UniversalContainer2:
    def __init__(self):
        self.capacity_ = 1
        # constructor for empty container
        # we reserve memory for at least one item
        self.data_ = [None]*self.capacity_ # the internal memory
        self.size_ = 0
        # no item has been inserted yet
    def size(self):
        return self.size_
    def capacity(self):
        return self.capacity_
    def push(self,item):
    # add item at the end
        if self.capacity_ == self.size_: # internal memory is full
            for x in range(self.capacity_):
                self.data_.append(None)
            self.capacity_*=2
        self.data_[self.size_] = item
        self.size_ += 1
    def popFirst(self):
        if self.size_ == 0:
            raise RuntimeError("popFirst() on empty container")
        out=self.data_[0]
        for x in range(self.size_-1):
            self.data_[x]=self.data_[x+1]
        self.size_-=1
        return out
    def popLast(self):
        if self.size_ == 0:
            raise RuntimeError("popLast() on empty container")
        out=self.data_[self.size_-1]
        self.size_-=1
    def __getitem__(self, index):# __getitem__ implements v = c[index]
        if index < 0 or index >= self.size_:
            raise RuntimeError('index out of range')
        return self.data_[index]
    def __setitem__(self, index, v): # __setitem__ implements c[index] = v
        if index < 0 or index >= self.size_:
            raise RuntimeError("index out of range")
        self.data_[index]=v
    def first(self):
        return self.data_[0]
    def last(self):
        return self.data_[self.size_-1]

class UniversalContainer3:
    def __init__(self):
        self.capacity_ = 1
        # constructor for empty container
        # we reserve memory for at least one item
        self.data_ = [None]*self.capacity_ # the internal memory
        self.size_ = 0
        # no item has been inserted yet
        self.anfangsindex=0;
        self.endindex=-1;
    def size(self):
        return self.size_
    def capacity(self):
        return self.capacity_
    def push(self, item):
    # add item at the end
        if(self.endindex==self.capacity_-1):
            if(self.anfangsindex>0):
                endindex=-1
            else:
                for x in range(self.capacity_):
                    self.data_.append(None)
                self.capacity_*=2
        self.data_[self.endindex+1] = item
        self.size_ += 1
        self.endindex+=1
    def popFirst(self):
        if self.size_ == 0:
            raise RuntimeError("popFirst() on empty container")
        out=self.data_[self.anfangsindex]
        self.anfangsindex+=1
        self.size_-=1
        return out
    def popLast(self):
        if self.size_ == 0:
            raise RuntimeError("popLast() on empty container")
        out=self.data_[self.endindex]
        self.endindex-=1
        self.size_-=1
        return out
    def __getitem__(self, index):# __getitem__ implements v = c[index]
        if index < 0 or index >= self.size_:
            raise RuntimeError('index out of range')
        return self.data_[index+self.anfangsindex]
    def __setitem__(self, index, v): # __setitem__ implements c[index] = v
        if index < 0 or index >= self.size_:
            raise RuntimeError("index out of range")
        self.data_[index+self.anfangsindex]=v
    def first(self):
        return self.data_[self.anfangsindex]
    def last(self):
        return self.data_[self.endindex]


def testContainer():

    c=UniversalContainer1()

    assert c.size() == 0
    assert c.size() <= c.capacity()
    c.push(0)
    assert c.first()==0
    oldsize=c.size()
    c.push(1)
    assert c.size()==oldsize+1
    assert c.last()==1
    assert c.first()==0
    c2=copy.deepcopy(c)
    c.push(2)
    c.popLast()
    assert c[0]==c2[0] and c[1]==c2[1]
    oldsize=c.size()
    c[1]=3
    assert c.size()==oldsize
    assert c[1]==3
    assert c[0]==0
    oldsize=c.size()
    c.popLast()
    assert c.size()==oldsize-1
    assert c[0]==0
    c.push(1)
    oldsize=c.size()
    c.popFirst( )
    assert c.size()==oldsize-1
    assert c[0]==1
    assert c.first() == c[0]
    assert c.last() == c[c.size()-1]

    c=UniversalContainer2()

    assert c.size() == 0
    assert c.size() <= c.capacity()
    c.push(0)
    assert c.first()==0
    oldsize=c.size()
    c.push(1)
    assert c.size()==oldsize+1
    assert c.last()==1
    assert c.first()==0
    c2=copy.deepcopy(c)
    c.push(2)
    c.popLast()
    assert c[0]==c2[0] and c[1]==c2[1]
    oldsize=c.size()
    c[1]=3
    assert c.size()==oldsize
    assert c[1]==3
    assert c[0]==0
    oldsize=c.size()
    c.popLast()
    assert c.size()==oldsize-1
    assert c[0]==0
    c.push(1)
    oldsize=c.size()
    c.popFirst( )
    assert c.size()==oldsize-1
    assert c[0]==1
    assert c.first() == c[0]
    assert c.last() == c[c.size()-1]

    c=UniversalContainer3()

    assert c.size() == 0
    assert c.size() <= c.capacity()
    c.push(0)
    assert c.first()==0
    oldsize=c.size()
    c.push(1)
    assert c.size()==oldsize+1
    assert c.last()==1
    assert c.first()==0
    c2=copy.deepcopy(c)
    c.push(2)
    c.popLast()
    assert c[0]==c2[0] and c[1]==c2[1]
    oldsize=c.size()
    c[1]=3
    assert c.size()==oldsize
    assert c[1]==3
    assert c[0]==0
    oldsize=c.size()
    c.popLast()
    assert c.size()==oldsize-1
    assert c[0]==0
    c.push(1)
    oldsize=c.size()
    c.popFirst( )
    assert c.size()==oldsize-1
    assert c[0]==1
    assert c.first() == c[0]
    assert c.last() == c[c.size()-1]

testContainer()


# repeat the test so many times

def timeout(n):
    global N
    N=n
    print(N)
    print("Push:")
    for x in range(1,5):

        initialisation = "c = UniversalContainer"+str(x)+"()"
        code_to_be_measured = '''for i in range(N):
            c.push(i)'''

        if(x==4):
            initialisation="c=[None]*1"
            code_to_be_measured = '''for i in range(N):
                c.append(i)'''

        repeats = 100

        # number of pushs to execute per test
        t = timeit.Timer(code_to_be_measured, initialisation, globals=globals())

        time = min(t.repeat(repeats, 1))
        print(x,": ","execution time:", (time*1000), "ms")

    print("popFirst:")
    for x in range(1,5):

        initialisation ='''c=UniversalContainer'''+str(x)+'''()
for x in range(N):
    c.push(x)'''
        code_to_be_measured = '''for i in range(N):
            c.popFirst()'''

        if(x==4):
            initialisation ='''c=[None]*1
for x in range(N):
    c.append(x)'''
            code_to_be_measured = '''for i in range(N):
                c.pop(0)'''
        repeats = 100

        # number of pushs to execute per test
        t = timeit.Timer(code_to_be_measured, initialisation, globals=globals())

        time = min(t.repeat(repeats, 1))
        print(x,": ","execution time:", (time*1000), "ms")


timeout(400)


'''
    U1 braucht beim Pushen länger als U2 ist aber schneller als U3
    Das ist nicht das was wir haben wollten aber macht sinn:
    U3 entfalltet nur sein Potential als ring, dafür müsste man aber popFirst()
    aufrufen
    list schläg aber alle um eine 10er Potenz

    bei PopFirst ist U3 100 mal schneller als U1 und U2
    list ist aber trotzdem noch 3mal so schnell wie U3
'''
