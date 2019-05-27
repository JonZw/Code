class Number():
    _num=None
    _left=None
    _right=None
    _who="Number"
    def __init__(self, number):
        self._num = number

class Operator():
    _num=None
    _left=None
    _right=None
    _who="Operator"
    def __init__(self,operator):
        self._num=operator

def parse(s):
    tree = []
    clip=False
    for x in range(len(s)):
        char=s[x]
        if(char>='0' and char<='9'):
            a=Number(int(char))
            if(len(tree)==0):
                tree.append(a)
            else:
                if(tree[len(tree)-1]._right==None):
                    tree[len(tree)-1]._right=a
                else:
                    pointer=tree[len(tree)-1]
                    while(pointer._right!=None):
                        pointer=pointer._right
                    pointer._right=a
        elif(char=='+' or char=='-'):
            a=Operator(char)
            a._left=tree.pop(len(tree)-1)
            tree.append(a)
        elif(char=='*' or char=='/'):
            a=Operator(char)
            if(clip==False):
                if(tree[-1]._who=="Operator"):
                    left=tree[-1]._right
                    tree[-1]._right=a
                    a._left=left
                if(tree[-1]._who=="Number"):
                    a=Operator(char)
                    a._left=tree.pop(len(tree)-1)
                    tree.append(a)
            else:
                a=Operator(char)
                a._left=tree.pop(len(tree)-1)
                tree.append(a)
                clip=False
        elif(char=='(' or char==')'):
            if(char==')'):
                clip=True
        else:
            print("syntaxfehler")

    return tree[0]

def evaluate(op):
    if(op._who=="Number"):
        return op
    if(op._left._who!="Number"):
        op._left=evaluate(op._left)
    if(op._right._who!="Number"):
        op._right=evaluate(op._right)
    if(op._num=='+'):
        return Number(op._left._num+op._right._num)
    if(op._num=='-'):
        return Number(op._left._num-op._right._num)
    if(op._num=='*'):
        return Number(op._left._num*op._right._num)
    if(op._num=='/'):
        return Number(op._left._num/op._right._num)

def evaluateTree(root):
    return evaluate(root)._num

def calculator():
    term=input()
    root=parse(term)
    print(evaluateTree(root))


calculator()

'''
b)
2+5*3

                +
              /   \
             2     X
                 /   \
                5     3

2*4*(3+(4-7)*8)-(1-6)

                                 -
                              /     \
                             *       -
                           /   \    /  \
                          *     +   1    6
                        /  \   /  \
                       2   4  3   *
                                /   \
                               -     8
                              / \
                             4   7
'''
