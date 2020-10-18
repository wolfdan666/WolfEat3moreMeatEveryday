def gcd(a,b):
    return a if b==0 else gcd(b,a%b)

def exgcd(a,b):
    if b==0:
        return 1,0
    y,x=exgcd(b,a%b)
    y-=(a//b)*x
    return x,y

def inv(a,b):
    x,y=exgcd(a,b)
    return (x%b+b)%b

n,M=map(lambda x:int(x),input().split(' '))
m=-1;c=-1
for i in range(n):
    a,b=map(lambda x:int(x),input().split(' '))
    if c==-1:
        m=a;c=b
    else:
        g=gcd(m,a)
        if (c-b)%g!=0:
            print('he was definitely lying')
            exit()
        c+=(inv(m//g,a//g)*(b-c)//g)%(a//g)*m
        m=m*a//g
if M>=c:
    print(str(c))
else:
    print('he was probably lying')