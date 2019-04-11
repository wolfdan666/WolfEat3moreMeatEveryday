// 2019年4月11日21:26:46开始看题
// 2019年4月11日21:34:33没有思路，emmm，想想暴力怎么做
// 2019年4月11日21:35:38突然灵机一动，直接都用最小串来比较对比get_minstring是O(100),再用set维护就行，1e6B=1e3K,可以的
// 2019年4月11日21:38:38队友说我们大创省赛申请过了，然后什么的，所以一直和其他人聊天到2019年4月11日22:27:50(主要是亲人聊天不敢断)
#include<bits/stdc++.h>
using namespace std;
set<string> s;
int n;

string get_minstring(string s)
{
    int len = int(s.length());
    int i = 0, j = 1, k = 0;
    while(i<len && j<len && k<len)
    {
        int t=s[(i+k)%len]-s[(j+k)%len];
        if(t==0)
            k++;
        else
        {
            if(t > 0)
                i+=k+1; // 保持i找到最小位置
            else
                j+=k+1;
            if(i==j) j++;
            k=0;
        }
    }
    // cout<<s<<"   debug1"<<endl;

    int start = min(i,j);
    char dest[105];
    for(int i=0,j=start;i<len;i++,j=(j+1)%len){
        dest[i]=s[j];
        // cout<<"dest[i]"<<dest[i]<<"  s[j]"<<s[j]<<endl;
    }
    // cout<<dest<<"   debug222"<<endl;
    // cout<<string(dest)<<"2222debug222"<<endl;

    dest[len]='\0';// (可能string的时候也不管'\0',只要你str[]搞过，就str返回空了？)
    // cout<<dest<<"   debug"<<endl;
    // cout<<string(dest)<<"2222debug22211111"<<endl;
    // 2019年4月11日22:52:26，今天没时间研究为什么了，先用数组转化先把
    string str(dest);
    return str;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    while(cin>>n) {
        string t;
        for(int i=0;i<n;i++){
            cin>>t;
            s.insert(get_minstring(t));
        }
        cout<<s.size()<<endl;
        s.clear();
    }
    return 0;
}