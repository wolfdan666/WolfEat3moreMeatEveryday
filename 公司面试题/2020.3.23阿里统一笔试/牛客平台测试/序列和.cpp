/*
思路就是求和公式各项之间的关系
因为 (end + start) * length / 2 = target
end - start = length

2020年3月23日15:53:05 开始写

2020年3月23日16:14:30 WA on
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例点击对比用例标准输出与你的输出
case通过率为20.00%

用例:
1000000000 2

对应输出应该为:

199999998 199999999 200000000 200000001 200000002

你的输出为:

No


输出测试: 2020年3月23日16:25:19 发现是tp整型溢出了...


2020年3月23日16:28:37, 原因是自己没有改回之前的代码，加上没有看到是非负数
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例点击对比用例标准输出与你的输出
case通过率为30.00%

用例:
4950 100

对应输出应该为:

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99

你的输出为:

No

2020年3月23日16:30:32 总算AC了，我佛了,变菜了好多，一个小时才过了一题，今天一定不能卡ll了...
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

int N, L;

int main(){
    N = rd(); L = rd();
    // int target = 2*N;
    long long target = 2*N;
    bool ok = false;

    int ansl;
    int i = L;
    for(; i <= 100; i++){

        // int l = 1,r = 5e8;
        int l = 0,r = 5e8;
        while(l < r){
            int mid = (l+r) >> 1;
            int s = mid,e = s + i - 1;
            // long long tp = (s+e)*i;
            long long tp = 1ll*(s+e)*i;
            // cout<< " tp: " << tp <<" target: " << target<<endl;
            if(tp == target){
                ansl = mid;
                ok = true;
                goto END;
            }
            if(tp < target) l = mid+1;
            else r = mid;

            // cout<< " test length i: "<< i <<" l: "<<l << " r: "<<r<<endl;
        }
    }
    END:
    if(ok){
        for(int j=0;j<i;j++)
            printf("%d%c", ansl+j," \n"[j==i-1]);
    } else {
        puts("No");
    }

    return 0;
}