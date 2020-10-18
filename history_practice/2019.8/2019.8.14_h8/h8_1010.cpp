#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+7;
int T,n;
double d;
struct node{
    string name;
    int p;
    int t;
} a[M];

bool cmp(node A,node B){
    return A.p!=B.p ? A.p>B.p : A.t<B.t;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i].name>>a[i].p>>a[i].t;
        }
        double tp = n*0.1*d;
        if(int(tp*10)%10 == 5){
            int tmp = tp+1;
            sort(a+1,a+1+n,cmp);
            cout<<a[tmp].name<<endl;
        }
        else{
            cout<<"Quailty is very great"<<endl;
        }
    }

    return 0;
}