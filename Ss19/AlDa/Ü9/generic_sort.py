import math
from functools import cmp_to_key

array=[2,-1,3,-4,5]
tupel=[("eins",1),("minuszwei",-2),("drei",3)]
array.sort(key = abs, reverse = False)
tupel.sort(key =lambda x: abs(x[1]), reverse= True)
print(array)
print(tupel)

from functools import cmp_to_key

array=[1, 4, 3, 5, 7, 2, 6]

def myCompare (x, y):
    if (x%2)==0:
        if (y%2)!=0:
            return -1
        else:
            if(x>y):
                return 1
            else:
                return -1
    else:
        if (y%2)==0:
            return 1
        else:
            if(x>y):
                return -1
            else:
                return 1

array.sort(key=cmp_to_key(myCompare))
print(array)


import unittest
class TestmyCompare(unittest.TestCase):
    def testmyCompare(self):
        a=[1,4,3,5,7,2,6]
        b=[2,4,6,7,5,3,1]
        a.sort(key=cmp_to_key(myCompare))
        assert a==b

if __name__=="__main__":
    unittest.main()
