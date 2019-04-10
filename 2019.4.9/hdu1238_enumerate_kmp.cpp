/*
第一题思路，先全连接，然后找出最多出现的串(次数a)，然后探索其翻转串数量(次数b)
a+b是否大于等于 n
然后增加串长   得到最大串长，但是要滑块...有则马上break
最坏结果 t*...
但是自己这个思路慌到自己不敢写，而且十分不明晰，看了别人的思路，才恍然大悟...

反思：自己没有想清楚模板串是谁，以及没有理顺思路！
*/

//别人的思路和code   http://www.acmsearch.com/article/show/10028
//求最大公共子串的长度；
//先进行排列，将各个的字符串按长度从小到大排；
//对最小的字符串进行它的子串和反串与其他的字符串的字串比较；
//这里用到几个函数；substr（i，j）是从字符串的地i的位置往后找j的长度的子串；
//append 是取反；
//str.find(temp)是找str字符串中含有temp的字串，并返回 temp在str的位置；

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string str[110];
int n, t;
bool cmp(string a, string b){ return a.length() < b.length();}

string qf(string a){ // 取反
    string b;
    int len = a.length();
    for(int i = len-1; i >= 0; i--){
       b.append(1, a[i]);
    }
    return b;
}

int pd(string a){
    int len = a.length();
    for(int i = len; i >= 1; i--){  // 从最短字串str[0]的全长开始递减长度
        for(int j = 0; j+i <= len; j++){ // 逐步漂移长度为i的滑块
            string temp = a.substr(j, i);
            string rtemp = qf(temp);
            int b = 1;
            for(int h = 1; h < n; h++){
                if(str[h].find(temp) != -1)
                    continue;
                if(str[h].find(rtemp)!=-1)
                    continue;
                b = 0;
                break;
            }
            if(b)
                return temp.length();
        }
    }
    return 0;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> str[i];
        }
        sort(str, str+n, cmp);
        int flag = pd(str[0]);
        cout << flag << endl;
    }
    return 0;
}