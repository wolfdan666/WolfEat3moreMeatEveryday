// 竟然wa了，想不通

#include<bits/stdc++.h>
using namespace std;
// vector<string> source;
int num=0;
set<string> sset;

int main(int argc, char const *argv[])
{
    int n,q;
    cin>>n>>q;
    string tem;
    while(n--){
        cin>>tem; num++; sset.insert(tem);
        // cin>>tem; source.push_back(tem); sset.insert(tem);
    }
    int t2;
    while(q--) {
        cin>>t2;
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