/*
2019年09月29日21:11:37 交了A
2019年09月29日21:13:40 又是一直in queue
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
int l,r;

bool check(int a){
    int cnt[10]={};
    while(a){
        cnt[a%10]++;
        a/=10;
    }
    for(int i=0;i<=9;i++) if(cnt[i]>=2) return false;
    return true;
}

int main(){
    l = rd(); r=rd();
    for(int i=l;i<=r;i++){
        if(check(i)){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",-1 );
    return 0;
}