// AC代码
// #include<bits/stdc++.h>
// using namespace std;
// int n, q, num, ans;
// string s;

// int main(){
//     map<string,bool>a;
//     cin >> n >> q;
//     for(int i = 0; i < n; i ++ ){
//         cin >> s;
//         if(a[s])  ans ++ ;
//         a[s] = 1;
//     }
//     for(int i = 0; i < q; i ++ ){
//         scanf("%d",&num);
//         if(num == 1){
//             cin >> s;
//             if(a[s])  ans ++ ;
//             a[s] = 1;
//         }
//         else{
//             cout << ans <<endl;
//             ans = 0;
//         }
//     }
//     return 0;
// }


// 我的一开始的代码只过了20%?
#include<bits/stdc++.h>
using namespace std;
// vector<string> source;
int num;
set<string> sset;

int main(int argc, char const *argv[]){
    // ios::sync_with_stdio(0);
    // cin::tie(0);
    int n,q;
    cin>>n>>q;
    string tem;
    while(n--){
        cin>>tem; num++; sset.insert(tem);
        // cin>>tem; source.push_back(tem); sset.insert(tem);
    }
    int t2;
    while(q--) {
        // cin>>t2;

        scanf("%d",&t2); // 实验发现...只有用scanf能过,牛客系统你玩我？


        // if(t2==1) cin>>tem,source.push_back(tem),sset.insert(tem);
        if(t2==1) cin>>tem,num++,sset.insert(tem);
        else{
            int t3 = num-sset.size();
            cout<<t3<<endl;
            num -= t3;
        }
    }
    return 0;
}