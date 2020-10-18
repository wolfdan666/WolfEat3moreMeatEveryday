// 2019年4月12日11:47:32
// 花了20mins检测得知，要如果要让string像char数组一样的操作，必须先resize，否则白做了，也可以先直接用char来做
// 然后后面直接转化成string  by  `string str(charstringName)`
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string s,s1="";
    s[0]='a';s[1]='b';s[2]='\0';
    s1[0]='a';s1[1]='b';s1[2]='\0';

    cout<<s1<<endl;
    cout<<"s1 Asize is :"<<s1.size()<<endl;
    printf(s.empty()?"Empty\n":"NO empty\n");

    s1.resize(3);
    s1[0]='a';s1[1]='b';s1[2]='\0';

    cout<<s1<<endl;
    cout<<"s1 Bsize is :"<<s1.size()<<endl;
    printf(s.empty()?"Empty\n":"NO empty\n");

    cout<<s<<endl;
    cout<<"s size is :"<<s.size()<<endl;
    printf(s.empty()?"Empty\n":"NO empty\n");

    cout<<endl;



    return 0;
}