/*
2019年7月6日14:56:09 开始第四题，有点慢  ，现在99 名 ...

__gcd(P,Q)==x0 可以求出最大公约数(或者手动辗转相除法)，然后最小公倍数就是P*Q/__gcd(P,Q)==y0

给了x0，y0   求  P,Q配对数

P*Q == x0*y0  (然后P，Q左右对称) (不妨设P<=Q)
min(x,y) <= P <= max(x,y)/2+1    // 题目设定应该是x0 <= y0             // 最大公约数和最小公倍数相等的情况是 原来的两个数P,Q相等--> 所以还是特殊判断一下x0=y0  \
除去上面的特殊情况...x<y，但是不一定证明 p一定<= y/2 ,不对，x*y==p*q,所以 p<=q的情况下，p<=sqrt(x*y)  --- 等于还是特判，所以可以安全小于，之后还能cnt*=2  得到ans
反例  1  35
1 35
5 7
5不小于7/2=3.5

而且第一组一定是x0,y0 因为这个是 P 最小的时候, 之后P+=x0 前进 ,odk

2019年7月6日15:10:32 开始写吧

2019年7月6日15:39:46 wa了，发现有1人ak了...
2019年7月6日15:58:56 中途处理了一下数电实验报告提交格式的事情，然后第二发又wa...
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,y,p,q;
ll cnt;

int main(){
    while(cin>>x>>y){// 因为是输入文件，所以这样写是没有问题的
        if(x==y){ cout<<1<<endl; continue; }
        ll tem = 1ll*x * y;
        int t = sqrt(tem);
        p = x,q = y,cnt = 0;
        for(;p<t;p+=x){

            // 看了大佬的代码，才发现自己错在q可能是除不尽的！ 然后被我int之后就导致了误判，导致cnt值偏大!
            // 而第二个大佬之所以能对 `(gcd(i, p) == a) && (lcm(i, p) == b)`  ，是因为其使用了两个判断条件，从而正好满足了  剔除掉除不尽的可能性！
            if(tem%p==0)

            if(__gcd(p,int(tem/p))==x) cnt++; // 这个就是整个条件满足的整合体，最大公约数满足之后，他们的乘积/最大公约 = 最小公倍必定满足    (int)tem/p可能会先转化，不会是这里wa了吧？
        }
        cout<<cnt*2<<endl;
    }
    return 0;
}

/*
// 2019年7月7日20:08:52 看别人的代码补题
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main(){
    ll a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        int cal = 0;
        for (int i = a; i <= b; i++) {
            if (i % a == 0) {
                int p = a * b / i;
                // 按照我的思路来讲，只要前面一个条件就行，可是去掉后面的条件就会wa！    不要把注释和代码放在同一行...
                // 但其实确实是可以去掉第二个条件的，说明其实还是有问题
                if ((gcd(i, p) == a) && (lcm(i, p) == b)) {
                    cal++;
                }
            }
        }
        cout << cal << endl;
    }
    return 0;
}


// 看另一个大佬的，这个人思路和我一样--- 不过比我的方法简洁，我搞了特判，而他的不用特判
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ll x, y;
    while (cin >> x >> y) {
        ll ans = 0;
        ll xy = x * y;
        ll Q;
        for (ll i = x; i <= y; i += x) {
            if (xy % i != 0)
                continue;
            Q = xy / i;
            if (gcd(i, Q) == x)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
*/