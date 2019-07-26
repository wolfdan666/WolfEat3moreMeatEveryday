#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 1e5+7;
int n;
char a[M];
int num[M];
map<int,int> G;
int z,o;

int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='1') o++,num[i]+=num[i-1]+1;
        else z++,num[i]+=num[i-1]-1;
    }
    int ans2 = 2*min(o,z);
    int ans = 0;
    G[0] = 0;
    for(int i=1;i<=n;i++){
        /*find是返回存在的key的二元组迭代器*/
        if(G.find(num[i])!=G.end()){
            ans = max(ans,i-G[num[i]]);
        } else {
            G[num[i]] = i;
        }
    }
    printf("%d %d\n", ans,ans2);

    return 0;
}