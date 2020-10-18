#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,a[105],p[105],base,M;

const char *definitely_lie = "he was definitely lying";
const char *probably_lie = "he was probably lying";

int main(){
    cin >> n >> M;
    /*这里是用p[i]去当除数留下(余下)a[i]个*/
    for (int i=0;i<n;i++) cin >> p[i] >> a[i];
    /*两两之间判断一次*/
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++){
        ll d=__gcd(p[i],p[j]);
        if (d!=1){
            if (a[i]%d!=a[j]%d){
                puts(definitely_lie);
                return 0;
            }
        }
    }
    ans=0; base=1;
    for (int i=0;i<n;i++){
        while (ans%p[i]!=a[i]) {
            ans+=base;
            if (ans>M){
                puts(probably_lie);
                return 0;
            }
        }
        ll gg=p[i]/__gcd(base,p[i]);
        /*base*gg就是新的最小公倍数
        一旦M小于了最小公倍数了，就是可能撒谎(因为之前确定了是存在一个的
        所以这里就在不满足条件的时候一定是可能撒谎而非一定撒谎的*/
        if (M/base>=gg) base*=gg;
        else {
            for (int j=i+1;j<n;j++) if (ans%p[j]!=a[j]){
                puts(probably_lie);
                return 0;
            }
            /*因为上面是下一个公倍数会超过，所以如果这里满足的话是可以的*/
            printf("%lld\n",ans);
            return 0;
        }
    }
    for (int i=0; i<n; i++) assert(ans % p[i] == a[i]);
    printf("%lld\n",ans);
    return 0;
}
