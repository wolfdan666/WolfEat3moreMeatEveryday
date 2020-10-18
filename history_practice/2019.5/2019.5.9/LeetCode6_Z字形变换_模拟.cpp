// 2019年5月9日17:05:25 完全的模拟
// 以为自己要输出z字形，然后自闭了一会，然后发现并不是，所以我就直接char二维数组就完事了
// 2019年5月9日17:28:17又发现好像就算让我输出z字形也很简单啊！mdzz了，就char二维转string而已 ， 不断+=

// 2019年5月9日17:43:16 发现自己行列写反了
// 发现memset之后确实是0.但是在赋值操作后，某些位置会有变化(多亏了VScode的Debug功能)，导致不能用if(a[i][j]) t+=a[i][j];，必须要一些其他的操作，就是判断是字符
// 莫名其妙的错误，吃饭后面再debug
// 看不出自己的程序错在哪？就是很奇怪的未改变的位置也发生了改变，先去和小姐姐跑步去，所以就明天再debug

/*
执行用时 : 20 ms, 在ZigZag Conversion的C++提交中击败了99.27% 的用户

内存消耗 : 10.1 MB, 在ZigZag Conversion的C++提交中击败了93.97% 的用户

没有用数组以及其他工具，依次找到第一行、第2行...第n行所取S中的字符，存入ans中，返回ans即可。

找到下标分布的规律：

第一行和最后一行取出字符串S的下标间隔为（numRows*2-2），因为中间有(numRows-1)行，而每行中有2个数字；

中间的每一行间隔有下三角部分和上三角部分，间隔分别为(numRows-row-1)*2、row*2；

                    发现大佬想得很清晰，而我却死在了内存问题上面

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string t;
        int slen = int(s.length());
        if(numRows>=slen||numRows==1)
            return s;
        char a[500][500];
        memset(a,0,sizeof(a));
        int n = numRows*2-2;
        int time = slen/n;
        int k=0;
        for(int i=1;i<=time;i++){
            int col = (i-1)*(numRows-1)+1;
            for(int j=1;j<=numRows;j++){
                a[j][col] = s[k++];
            }
            for(int j=1;j<=numRows-2;j++){
                a[numRows - j][col + j] = s[k++];
            }
        }
        int col = time*(numRows-1)+1;

        int f=1;
        for(int j=1;f&&j<=numRows;j++){
            a[j][col] = s[k++];
            if(k==slen) {f=0;break;}
        }
        for(int j=1;f&&j<=numRows-2;j++){
            a[numRows - j][col + j] = s[k++];
            if(k==slen) {f=0;break;}
        }

        // 输出开始
        int nn = col + numRows-2;
        for(int i=1;i<=nn;i++){
            for(int j=1;j<=nn;j++){
                // cout<<a[i][j]<<endl;
                if((a[i][j]>=65&&a[i][j]<91) ||(a[i][j]>=97&&a[i][j]<123)) t+=a[i][j];
            }
        }
        return t;
    }
};

class Solution_dalao {
public:
    string convert(string s, int numRows) {
        int length=s.length();
        if(numRows>=length||numRows<2) return s;
        string ans;
        for( int row=0;row<numRows;row++){
            int i=row;
            if(row==0||row==numRows-1){
                while(i<length){
                    ans+=s[i];
                    i+=numRows*2-2;
                }
            }
            else{
                while(i<length){
                 ans+=s[i];
                 i+=(numRows-row-1)*2;
                    if(i<length){
                        ans+=s[i];
                        i+=row*2;
                    }
                }
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    string s;int numRows;
    Solution solve;
    Solution_dalao solve2;
    while(cin>>s>>numRows){
        cout<<solve.convert(s,numRows)<<endl;
        cout<<solve2.convert(s,numRows)<<endl;
    }
    return 0;
}