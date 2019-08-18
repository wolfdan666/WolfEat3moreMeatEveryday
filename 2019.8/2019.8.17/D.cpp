#include <bits/stdc++.h>
using namespace std;
const int MAXN = 401;
struct bign
{
    int len, s[MAXN];
    bign ()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign (int num) { *this = num; }
    bign (const char *num) { *this = num; }
    bign operator = (const int num)
    {
        char s[MAXN];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator = (const char *num)
    {
        for(int i = 0; num[i] == '0'; num++) ;
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }
    bign operator + (const bign &b) const
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)
        {
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator += (const bign &b)
    {
        *this = *this + b;
        return *this;
    }
    void clean()
    {
        while(len > 1 && !s[len-1]) len--;
    }
    bign operator * (const bign &b)
    {
        bign c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < b.len; j++)
            {
                c.s[i+j] += s[i] * b.s[j];
            }
        }
        for(int i = 0; i < c.len; i++)
        {
            c.s[i+1] += c.s[i]/10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bign operator *= (const bign &b)
    {
        *this = *this * b;
        return *this;
    }
    bign operator - (const bign &b)
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; i < len; i++)
        {
            int x = s[i] - g;
            if(i < b.len) x -= b.s[i];
            if(x >= 0) g = 0;
            else
            {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bign operator -= (const bign &b)
    {
        *this = *this - b;
        return *this;
    }
    bign operator / (const bign &b)
    {
        bign c, f = 0;
        for(int i = len-1; i >= 0; i--)
        {
            f = f*10;
            f.s[0] = s[i];
            while(f >= b)
            {
                f -= b;
                c.s[i]++;
            }
        }
        c.len = len;
        c.clean();
        return c;
    }
    bign operator /= (const bign &b)
    {
        *this  = *this / b;
        return *this;
    }
    bign operator % (const bign &b)
    {
        bign r = *this / b;
        r = *this - r*b;
        return r;
    }
    bign operator %= (const bign &b)
    {
        *this = *this % b;
        return *this;
    }
    bool operator < (const bign &b)
    {
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
    bool operator > (const bign &b)
    {
        if(len != b.len) return len > b.len;
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != b.s[i]) return s[i] > b.s[i];
        }
        return false;
    }
    bool operator == (const bign &b)
    {
        return !(*this > b) && !(*this < b);
    }
    bool operator != (const bign &b)
    {
        return !(*this == b);
    }
    bool operator <= (const bign &b)
    {
        return *this < b || *this == b;
    }
    bool operator >= (const bign &b)
    {
        return *this > b || *this == b;
    }
    string str() const
    {
        string res = "";
        for(int i = 0; i < len; i++) res = char(s[i]+'0') + res;
        return res;
    }
};
istream& operator >> (istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bign &x)
{
    out << x.str();
    return out;
}

typedef bign ll;

ll Mod;

// ll __gcd(ll a, ll b)
// {
//     ll zero = 0;
//     if(b == zero) return a;
//     return __gcd(b, a % b);
// }

ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll d = Extend_Euclid(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return d;
}

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
    ll x,y;
    ll t = Extend_Euclid(a,n,x,y);
    if(t != 1)
        return -1;
    return (x%n+n)%n;
}

//将两个方程合并为一个
bool merge(ll a1, ll n1, ll a2, ll n2, ll& a3, ll& n3)
{
    ll d = __gcd(n1,n2);
    //cout << d << endl;
    ll c = a2-a1;
    if(c%d > 0)
        return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1,n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}

//求模线性方程组x=ai(mod ni),ni可以不互质
ll China_Reminder2(int len, ll* a, ll* n)
{
    ll a1=a[0],n1=n[0];
    ll a2,n2;
    for(int i = 1; i < len; i++)
    {
        ll aa,nn;
        a2 = a[i],n2=n[i];
        if(!merge(a1,n1,a2,n2,aa,nn))
            return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return (a1%n1+n1)%n1;
}
ll a[1000],b[1000];
int main()
{
    int n;
    ll m;
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
        ll res = China_Reminder2(n,b,a);
        if(res == -1) printf("he was definitely lying\n");
        else if(res > m) printf("he was probably lying\n");
        else cout << res << endl;
    }

    return 0;
}

/*

4 10000
12 7
15 2
30 5
8 6
 */