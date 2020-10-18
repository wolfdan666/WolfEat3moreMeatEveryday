#include<bits/stdc++.h>
using namespace std;
vector<string> s(10);
vector<int> t;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int i=0;
    string word;

    t.push_back(1);
    // s.push_back("start");
    for(int j=0;j<n;j++){
        cin>>t[j];cout<<t[j]<<"&t.size"<<t.size()<<endl;
        cin>>s[j];cout<<s[j]<<"end"<<endl;
    }

    int tem;
    while(n--) {
        // cin>>s[i];
        // cin>>word>>t[i];
        cin>>word>>tem;
        s.push_back(word);
        t.push_back(tem);
        cout<<s[i]<<t[i]<<endl;
        i++;
    }
    n = i;
    cout<<"here1"<<endl;
    t[-1]=5555;
    cout<<" "<<t[-1]<<endl;
    cout<<s[n-1]<<" "<<t[n-1]<<endl;// 一到s[n-1]就直接退出！！！因为n--了，mdzz,(加上n=i就ok了)所以说vector<int> t可以对-1位置直接赋值输出！
    cout<<"here2"<<endl;
    s[n-1]="fu zhi bu shi chu shi hua";
    // s[n-1]="ee";
    cout<<s[n-1]<<" "<<t[n-1]<<endl;
    cout<<"here"<<endl;
    return 0;
}