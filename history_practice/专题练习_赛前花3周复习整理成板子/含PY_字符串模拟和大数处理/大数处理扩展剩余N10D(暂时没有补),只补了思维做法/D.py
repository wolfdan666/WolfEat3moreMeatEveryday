# 自己以前按照cpp瞎改的

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

def Extend_Euclid(a,b,&x,&y):
    if b==0:
        x,y=1,0
        return a
    d = Extend_Euclid(b,a%b,x,y)
    t = x
    x = y
    y = t -a/b*y
    return d

def inv(a,b):
    int x,y
    t = Extend_Euclid(a,n,x,y)
    if t != -1:
        return -1
    return (x%n+n)%n

def bool merge(a1,n1,a2,n2,&a3,&n3):
    d = gcd(n1,n2)
    c = a2 - a1
    if(c%d):
        return False
    c = (c%n2 + n2)%n2
    c = c/d
    n1 = n1/d
    n2 = n2/d
    c = c*inv(n1,n2)
    c = c%n2
    c = c*n1*d
    n3 = n1*n2*d
    a3 = (c%n3+n3)%n3
    return True

def China_Reminder2(len,*a,*n):
    a1,n1 = a[0],n[0]
    a2,n2 = 0,0
    for i in range(1,len):
        aa,nn = 0,0
        a2,n2 = a[i],n[i]
        if merge(a1,n1,a2,n2,aa,nn) == False:
            return -1
        a1,n1 = aa,nn
    Mod = n1
    return (a1%n1+n1)%n1

a = [],b = []

def main():
    int n,m
    n,m = eval(input()),eval(input())
    for i in range(n):
        a[i],b[i] = eval(input()),eval(input())
    res = China_Reminder2(n,b,a)
    if res = -1 :
        print("he was definitely lying\n")
    elif res > m:
        print("he was probably lying\n")
    else print(res)
    return 0

main()