// 2019年5月9日16:25:24典型Manacher回忆默写
// 2019年5月9日16:29:15好吧直接想有点复杂，这种一般深刻理解了还是用板子提提速度

// 2019年5月9日16:55:43 第一发  Line 19: Char 21: runtime error: index 1010 out of bounds for type 'int [1010]' (solution.cpp)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Init
        string t;
        int len = int(s.length());
        t += "$#";
        for(int i=0;i<len;i++){// t的i/2-1对应s的i
            t += s[i];
            t += '#';
        }

        int p[2010];int ans_start=0;int max_len=0;
        // int p[1010];int ans_start=0;int max_len=0;

        // Manacher
        int mx=0,id=0;
        for(int i=1;i<=int(t.length());i++){
            if(mx>i) p[i]=min(p[2*id-i],mx-i);
            else p[i]=1;

            while(i-p[i]>=0&&t[i-p[i]]==t[i+p[i]]) p[i]++;
            if(i+p[i]>mx){
                mx=i+p[i];
                id=i;
            }
            if(p[i]-1>max_len){
                max_len = p[i]-1;
                ans_start=(id-(p[i]-1)+1)/2-1;
            }
        }
        return s.substr(ans_start,max_len);
    }
};

int main(int argc, char const *argv[])
{
    string s;
    while(cin>>s){
        Solution solve;
        cout<<solve.longestPalindrome(s)<<endl;
    }
    return 0;
}