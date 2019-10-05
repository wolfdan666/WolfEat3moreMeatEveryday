/*
等下就要打CF了,,,自己竟然卡在了自己的kmp...真傻比,但是为了节约时间,所以先借鉴一下别人的代码


求的是后缀的循环节长度B和循环节出现的总长度(包含不完整循环节)A，给定a和b求，最大的aA-bB，显然kmp反过来后跑一下求出next数组，
枚举前缀，那么i就是循环节出现的总长度，而i−next[i]就是循环节长度了，直接更新最大值，a，b和ans都需要ll，答案可能有负数，初值要设为-1e18。
————————————————
版权声明：本文为CSDN博主「nuoyanli」的原创文章，遵循 CC 4.0 BY 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/nuoyanli/article/details/101618807


发现是自己傻逼了,竟然都不理解kmp的get_next是要延后一个位置使用了!!!
然后用cin, TLE一发 , 然后又WA了...???  因为 后面b*(i-fail[i])也要先乘以`1ll`!
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
const int M = 1e7+10;
char s[M],tp[M];
int a,b,fail[M];
// string tp;

// 抄板子
void getFail(char *b,int *f){
    int m = strlen(b);
    f[0]=0;f[1]=0;
    for(int i=1;i<m;i++){
        int j=f[i];
        while(j&&b[i]!=b[j]) j=f[j];
        f[i+1] = b[i]==b[j]? j+1:0;
    }
}

int main(){
    // a = rd(); b = rd();
    while(~scanf("%d%d",&a,&b)){
        ll ans = -1e18;
        // cin>>tp;
        scanf("%s",tp);

        int tp_len = strlen(tp); bool flag = 0;int pos = 0;
        for(int i=0;i<tp_len;i++){
            if(!flag){
                if(tp[i]=='.') flag = 1,pos = i;
            } else {
                // s[(tp_len-1) - pos - (i - pos)] = tp[i];
                s[(tp_len-1) - i] = tp[i];
            }
        }

        int len = (tp_len-1) - pos;
        s[len] = '\0';
        
        // cout<<s<<endl;
        
        getFail(s,fail);
        // for(int i=0;i<len;i++)cout<<fail[i]<<" "; cout<<endl;
        // for(int i=1;i<=len;i++)cout<<fail[i]<<" "; cout<<endl;

        // for(int i=0;i<len;i++){
        for(int i=1;i<=len;i++){
            ans = max(ans,1ll*a*i-1ll*b*(i-fail[i]));
            // cout<<"ans_tp:"<<1ll*a*(i+1)-b*fail[i]<<" fail: "<<fail[i]<<endl;
        }
        // cout<<ans<<endl;
        printf("%lld\n",ans );
    }
    
    return 0;
}


// nuoyanli
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long int
#define mod 998244353
using namespace std;

const int N = 1e7 + 10;
char s[N], s1[N];
ll len, t, nxt[N];
inline void get_next(int len) {
  int i, j;
  nxt[0] = -1;
  for (i = 0; i < len; ++i) {
    j = nxt[i];
    while (j != -1 && s[j] != s[i])
      j = nxt[j];
    nxt[i + 1] = j + 1;
  }
}
signed main() {
  ll a, b;
  while (~scanf("%lld %lld", &a, &b)) {
    scanf("%s", s1);
    int len2 = strlen(s1) - 1;
    int tot = 0;
    // 下面这里确实写得比我写的优美多了
    for (int i = len2; i >= 0; i--) {
      if (s1[i] == '.')
        break;
      s[tot++] = s1[i];
    }
    len = strlen(s);
    get_next(tot);
    ll ans = -1e18;
    for (int i = 1; i <= tot; i++) {
      ans = max(ans, a * i - b * (i - nxt[i]));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
