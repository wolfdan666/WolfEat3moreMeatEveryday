#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
//当合并这两个集合的时候，应该将这两个集合合并后消失的贡献减去
//消失的贡献就应该是选择了一个a，选择了一个b，从剩下的众多集合中选择两个(即cd,ce,ef......)那么这个怎么算呢，可以用完全平方公式来推导
//(a+b+c+d)^2=a^2+b^2+c^2+d^2+2ab+2ac+2bc+2ad+2bd+2cd  所以众多集合中选择任意选择两个的情况可以用（和的平方-平方的和）/2来求（最重要的一步）
const int maxn = 1e5+5;
int pre[maxn];
ll size[maxn];
int get(int x){
    if(x==pre[x]) return x;
    int px = get(pre[x]);
    pre[x] = px;
    return px;
}
int join(int x,int y){
    pre[get(x)] = get(y);
    return 0;
}
int main(){
    ll n,m;
    cin>>n>>m;
    ll kind = 0;     //每个集合找两个人的种类数（现在是一个集合一个人，现实考虑可以找两个相同的人）
    ll cnt = 0;      //总人数
    for(int i = 1;i<=n;i++){
        pre[i] = i;
        size[i] = 1;   //还是每个集合新设置为只有一个元素
        kind += size[i]*size[i];
        cnt+=size[i];
    }

    ll ans = 1ll*n*(n-1)/2*(n-2)/3*(n-3)/4;     //最开始的四元组的个数
    int x,y;
    while(m--){
        cout<<ans<<endl;
        cin>>x>>y;
        x = get(x);
        y = get(y);
        if(x==y||ans==0)
            continue;      //这样的话其实后边的合并操作就不用再做了
        kind -=(size[x]*size[x]+size[y]*size[y]);  //因为要求平方的和吗，但是x和y已经被选定了，所以就减掉（平方的和）
        //cout<<"kind"<<kind<<endl;
        cnt-=(size[x]+size[y]);   //要准备和的平方
        //cout<<"cnt"<<cnt<<endl;
        ans-=(cnt*cnt-kind)/2*size[x]*size[y];
        size[y]+=size[x];
        pre[x] = y;
        kind+=size[y]*size[y];
        cnt+=size[y];
    }
    cout<<ans<<endl;
    //cout<<(long long)100000*99999*99998*99997/24<<endl;
    return 0;
}