# import math

T = int(input())
for t in range(T):
    # input()会吞一行,所以第一种写法不行..
    # a,b,m = int(input()),int(input()),int(input())
    a,b,m = map(lambda x:int(x),input().split(' '))
    if b==0:
        print('1')
    else:
        tp = 1
        for i in range(b):
            tp = a**tp
        print(tp%m)