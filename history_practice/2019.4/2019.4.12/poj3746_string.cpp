// 2019年4月12日13:50:48开始看题(其实为了节约时间,上午上课前的时候看了一点点)
// 看懂了题目意思，但是没什么思路，所以先想出写下最粗暴的方法先
// 就是  先 检测 Subject Verb (Object)  然后再逐个检测  他们是否符合使用规范  用一种怎样的方式呢？

// 2019年4月12日14:25:54 上了个WC，然后看了一下大佬的，以及打表的(600多行)，感觉被惊到了
// 然后选了一个比较理性分析的大佬(真orz2)的code:   https://blog.csdn.net/wl16wzl/article/details/79245191

// 然后发现今天poj服务器挂掉了，所以只能晚点交了  2019年4月12日14:45:15(加上上wc花了接近一个小时，要加速啊！)

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
using namespace std;
map<string,int> fun; //把每种词标号
map<string,int> num; //将题目中给出的词标号
map<string,char> str; //记录每种主语宾语谓语介词短语的每种形式，打表
map<string,int> ste; //每种句子形式，打表
void init()
{
    fun["n."]=0;
    fun["pron."]=1;
    fun["adj."]=2;
    fun["adv."]=3;
    fun["prep."]=4;
    fun["art."]=5;
    fun["vt."]=6;
    fun["vi."]=7;
    fun["v."]=8;

    str["450"]='A'; //介词短语
    str["4520"]='A';
    str["41"]='A';
    str["1"]='S'; //主/宾语
    str["50"]='S';
    str["520"]='S';
    str["7"]='I'; //不及物谓语
    str["37"]='I';
    str["6"]='T'; //及物谓语
    str["36"]='T';
    str["8"]='V'; //通用谓语
    str["38"]='V';
    //句子可能的总体结构    (就是对于A的不同位置插入)
    ste["SI"]=1;
    ste["STS"]=1;
    ste["SV"]=1;
    ste["SVS"]=1;
    ste["ASI"]=1;
    ste["ASTS"]=1;
    ste["ASV"]=1;
    ste["ASVS"]=1;
    ste["SAI"]=1;
    ste["SATS"]=1;
    ste["SAV"]=1;
    ste["SAVS"]=1;
    ste["SIA"]=1;
    ste["STAS"]=1;
    ste["SVA"]=1;
    ste["SVAS"]=1;
    ste["STSA"]=1;
    ste["SVSA"]=1;
}
int n,m;
int main()
{
    string a,b;
    init();
    scanf("%d%d",&n,&m);
    while(n--)
    {
        cin>>a>>b;
        num[a]=fun[b];
    }
    while(m--)
    {
        bool flag=false;
        b="";
        while(cin>>a) //转化为词性表示
        {
            if(isupper(a[0])) a[0]=a[0]+32;
            int len=a.length();
            if(a[len-1]=='.')
            {
                flag=true;
                a.erase(len-1,1);
            }
            if(a[len-1]==',') a.erase(len-1,1);
            b+='0'+num[a];
            if(flag) break;
        }
        //cout<<b<<endl;
        string c,d;
        c=d="";
        for(int i=0;i<b.length();i++) //转化为结构表示
        {
            c+=b[i];
            if(str[c])
            {
                d+=str[c];
                c="";
            }
        }
        d+=c;
        //cout<<d<<endl;
        if(ste[d]) cout<<"YES"<<endl; //判断是否符合
        else cout<<"NO"<<endl;
    }
    return 0;
}