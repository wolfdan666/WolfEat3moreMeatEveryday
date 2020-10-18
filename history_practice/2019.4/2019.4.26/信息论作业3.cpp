// 2019年4月26日18:58:53 开始查资料写 信息论  的实验报告，对我而言，实验报告(总成绩30%分数)是写一个比较简单的编码算法还是很幸福的
// 于是下午吃完饭回来就写

// 设信源可能输出的符号是a, b, c 三个字母，构成一个二阶Markov信源，且各阶条件概率如下，
// 试编写程序可以对任意字母序列（如abbcabcb）进行基于上下文的自适应算术编码，并进行相应的译码。

// emmm ,都90mins了,2019年4月26日20:26:13 还在发呆编写encord，加速啊！！！再给30mins必须编写完毕
// 2019年4月26日21:06:14 两个小时了，写encord还错了...emmm，星期五状态奇差，放假吧今天，odk
// 然后开始边听歌边聊天边写到2019年4月26日22:10:39(用了一个小时完善了encord，但是decode有点难，明天写)

#include<bits/stdc++.h>
using namespace std;
string s,ans,t;
double table[4][4][4];// eg: c/ab [1][2][3]   c/a [1][3][0]  a [1][0][0]
int l;

void Init(){
    for(int i=1;i<=3;i++){
        table[i][0][0] = 1/3.0;
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            if(i==j) table[i][j][0]=0.5;
            else table[i][j][0]=0.25;
        }
    }
    // 有点机械，还好sublime有多点编辑
    table[1][1][1]=3/5.0;    table[1][1][2]=1/5.0;    table[1][1][3]=1/5.0;
    table[1][2][1]=1/4.0;    table[1][2][2]=1/4.0;    table[1][2][3]=1/2.0;
    table[1][3][1]=1/4.0;    table[1][3][2]=1/4.0;    table[1][3][3]=1/2.0;
    table[2][1][1]=1/2.0;    table[2][1][2]=1/4.0;    table[2][1][3]=1/4.0;
    table[2][2][1]=1/5.0;    table[2][2][2]=3/5.0;    table[2][2][3]=1/5.0;
    table[2][3][1]=1/4.0;    table[2][3][2]=1/4.0;    table[2][3][3]=1/2.0;
    table[3][1][1]=1/2.0;    table[3][1][2]=1/4.0;    table[3][1][3]=1/4.0;
    table[3][2][1]=1/2.0;    table[3][2][2]=1/4.0;    table[3][2][3]=1/4.0;
    table[3][3][1]=1/5.0;    table[3][3][2]=1/5.0;    table[3][3][3]=3/5.0;
}

void encord(){// 老师用be end 算 len (概率长度) ,我觉得用p (概率长度) 算前后更方便
    // 维护 p ,be , end , 之后用be ，end算出概率，p算出编码长度,之后便可以编码
    cout<<"编码开始"<<endl;
    int n = int(s.length());
    double be = 0.0,end = 1.0;
    double p = 1.0;
    for(int i=0;i<n;i++){
        int k = s[i] - 'a' + 1;
        int kp=0,kpp=0;
        if(i==0){
            if(k==1){ end = 1/3.0;}
            else if(k==2){ be = 1/3.0; end = 2/3.0;}
            else be = 2/3.0;
            p = 1/3.0;
        }
        else if(i==1){
            kp = s[i-1] - 'a' + 1;
            if(k==1){
                p *= table[kp][k][0];
                end = be + p;
            }
            else if(k==2){
                p *= table[kp][k][0];
                be += table[kp][k-1][0];
                end = be + p;
            }
            else{
                p *= table[kp][k][0];
                be = end - p;
            }
        }
        else{
            kp = s[i-1] - 'a' + 1;
            kpp = s[i-2] - 'a' + 1;
            if(k==1){
                p *= table[kpp][kp][k];
                end = be + p;
            }
            else if(k==2){
                // p *= table[kpp][kp][k];
                // be += table[kpp][kp][k-1];// 这里有bug
                // end = be + p;
                be += p*table[kpp][kp][k-1];// 原来的长度*第一段
                p *= table[kpp][kp][k];
                end = be + p;
            }
            else{
                p *= table[kpp][kp][k];
                be = end - p;
            }
        }
        // cout<<"p监控:"<<p<<endl;
        // cout<<"be:  "<<be<<endl;
        // cout<<"end: "<<end<<endl;
    }
    l = ceil(log(1/p)/log(2));
    cout<<"be:"<<be<<"end:"<<end<<endl;
    double tp = 0.01*be + 0.99*end;
    int tp2;
    ans.resize(0);
    for(int i=0;i<l;i++){
        tp *= 2;
        tp2 = (int)tp;
        tp -= tp2;
        ans += char(tp2+'0');
    }
    cout<<"编码长度为: "<<l<<endl;
    cout<<"编码结果为: "<<ans<<endl;
}

void decord(){
    cout<<"译码: "<<endl;
    double result = 0.0;double w = 0.5;
    for(int i=0;i<l;i++,w*=0.5){
        result += w*(ans[i]-'0');
    }
    cout<<"译码选取的数字为:"<<result<<endl;
    for(int i=0;i<l;i++){
        double **tp;double *tp2;
        t.resize(0);
        if(i==0){// 记住左闭右开
            if(result<1/3.0){
                t+='a';
                tp=&table[1];
            }
            else if(result<2/3.0){t+='b';
            else t+='c';
        }
        else if(i==1){
            kp = s[i-1] -
        }
    }
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    Init();
    cout<<"请输入需要编码的字符序列(编码符号为a,b,c):"<<endl;
    // cout<<table[1][1][1]<<endl;
    while(cin>>s&&s[0]!='#'){
        encord();
        decord();
        cout<<"是否验证下一个字符序列,是则输入,否则输入#:"<<endl;
    }
    return 0;
}