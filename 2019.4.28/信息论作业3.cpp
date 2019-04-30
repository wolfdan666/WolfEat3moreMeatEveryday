// 2019年4月26日18:58:53 开始查资料写 信息论  的实验报告，对我而言，实验报告(总成绩30%分数)是写一个比较简单的编码算法还是很幸福的
// 于是下午吃完饭回来就写

// 设信源可能输出的符号是a, b, c 三个字母，构成一个二阶Markov信源，且各阶条件概率如下，
// 试编写程序可以对任意字母序列（如abbcabcb）进行基于上下文的自适应算术编码，并进行相应的译码。

// emmm ,都90mins了,2019年4月26日20:26:13 还在发呆编写encord，加速啊！！！再给30mins必须编写完毕
// 2019年4月26日21:06:14 两个小时了，写encord还错了...emmm，星期五状态奇差，放假吧今天，odk
// 然后开始边听歌边聊天边写到2019年4月26日22:10:39(用了一个小时完善了encord，但是decode有点难，明天写)


// 2019年4月27日20:07:47 继续回来写解码
// 2019年4月27日22:38:29 绝了，今天写bug改bug花了2小时，然后讨论自动化训练调参又花了30mins,网上也没仔细研究...算了先



/*        // 经过研究发现，长度变长的时候会出现不相等的情况，分析得知，是因为算法本身的概率选取的调整问题double tp = 0.01*be + 0.99*end;
        // 选取时应该把tp调整到大区间段(个人猜测，不会证明，但可以写一个循环自动化调参训练...当在某个长度(input)上面达到某个精度的时候输出参数)
        // input : length  先建立 length 长的全 a 序列, length重循环  最后一个从 a+0到+1到+2(最内层),每个外层一变化都要变化一次,O(3^length)指数爆炸
        for(double i=0.01;i<1.00;i+=0.01){
            for()// length重for3循环，后面计算  sumOf((s<t)||(s>t)) / 3^length  错误率...维护错误率min的i值 看i为多少的时候l错误率最低
        }

发现还有是精度问题，如果p后面变得很小的时候，那判断的时候很可能去掉几位判断
最近这几天事情比较多，所以就不写高精度的小数计算了
        */



#include<bits/stdc++.h>
using namespace std;
string s,ans,t;
double table[4][4][4];// eg: c/ab [1][2][3]   c/a [1][3][0]  a [1][0][0]
int sl;// s 的长度
int l; // 码符号长度

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
    int k = s[0] - 'a' + 1;
    int kp=0,kpp=0;
    for(int i=0;i<n;i++){
        if(i==0){
            if(k==1){end = 1/3.0;}
            else if(k==2){ be = 1/3.0; end = 2/3.0;}
            else be = 2/3.0;
            p = 1/3.0;
        }
        else if(i==1){
            // kp = s[i-1] - 'a' + 1;/// 我也是醉了，昨天状态不佳的时候写了多少bug，我以后再在状态不好时写代码我是狗
            kp = k;
            k = s[i] - 'a' + 1;
            if(k==1){
                p *= table[kp][k][0];
                end = be + p;
            }
            else if(k==2){
                be += p*table[kp][k-1][0];
                p *= table[kp][k][0];
                // p *= table[kp][k][0];  // 昨天写的bug 真牛逼
                // be += table[kp][k-1][0];
                end = be + p;
            }
            else{
                p *= table[kp][k][0];
                be = end - p;
            }
        }
        else{
            kpp = kp;
            kp = k;
            // kp = s[i-1] - 'a' + 1;// 昨天的bug
            // kpp = s[i-2] - 'a' + 1;
            k = s[i] - 'a' + 1;
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
        // cout<<"s[i]"<<s[i]<<endl;
        // cout<<"kpp:"<<kpp<<" kp:"<<kp<<" k:"<<k<<endl;
        // cout<<"p监控:"<<p<<endl;
        // cout<<"be:  "<<be<<endl;
        // cout<<"end: "<<end<<endl;
    }
    l = ceil(log(1/p)/log(2));
    // cout<<"be:"<<be<<"end:"<<end<<endl;


    // double tp = 0.5*be + 0.5*end;
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
    sl = int(s.length());
}

void decord(){
    cout<<"\n译码: "<<endl;
    double res = 0.0;double w = 0.5;
    for(int i=0;i<l;i++,w*=0.5){
        res += w*(ans[i]-'0');
    }
    cout<<"译码选取的数字为:"<<res<<endl;
    int a=0,b=0;     // 用a,b,c来记录下一个概率分布数组
    double p = 1;  //还是需要记录一个p(概率长度),因为这里的table是通用映射表，需要加约束
    t.resize(0);
    double be = 0/*,end = 1*/;// 其实不用end
    // cout<<"sl:"<<sl<<endl;
    for(int i=0;i<sl;i++){// mdzz 了，昨天居然把这些量放在里面了
        // 2019年4月27日20:52:03 发现还是不能仅跟长度对比啊，没有be，end不行
        // double **tp;double *tp2;
        // int a=0,b=0;     // 用a,b,c来记录下一个概率分布数组
        // double p = 1;  //还是需要记录一个p(概率长度),因为这里的table是通用映射表，需要加约束
        // t.resize(0);
        if(i==0){// 记住左闭右开
            if(res<1/3.0){t+='a';a = 1;be = 0.0;}
            else if(res<2/3.0){t+='b'; a = 2; be = 1/3.0;}
            else {t+='c';a = 3; be = 2/3.0;}
            p = 1/3.0;
        }
        else if(i==1){
            if(res < be + p*table[a][1][0]){//be 不变
                t += 'a'; b = 1;
                p *= table[a][1][0];
            }
            else if(res < be + p*(table[a][2][0]+table[a][1][0])){
            // else if(res < be + p*table[a][2][0]){//  写一个信息论的实验报告写了这么多bug，我不配打ACM,哭了
                t += 'b'; b = 2;
                be += p*(table[a][1][0]);
                // be += p*table[a][2][0]; // 2019年4月27日21:49:18今天的bug也很抠脚
                p *= table[a][2][0];
            }
            else{
                t += 'c'; b = 3;
                be += p*(table[a][1][0]+table[a][2][0]);
                // be += p*table[a][3][0];
                p *= table[a][3][0];
            }
        }
        else{// eg: c/ab [1][2][3]   c/a [1][3][0]  a [1][0][0]自己开始的假设碰巧有一致性，下次还是要打草稿
            // 2019年4月27日21:57:56 发现今天的bug，要先p*=table[a][b][1]再更新a,b
            if(res < be + p*table[a][b][1]){
                t += 'a'; /*a = b; b = 1;*/
                p*=table[a][b][1];// 更新a,b的值
                a = b; b = 1;
            }
            else if(res < be + p*(table[a][b][2]+table[a][b][1])){
                t += 'b'; //a = b; b = 2;
                be += p*table[a][b][1];
                // be += p*table[a][b][2];
                p*=table[a][b][2];
                a = b; b = 2;
            }
            else{
                t += 'c'; //a = b; b = 3;
                be += p*(table[a][b][2]+table[a][b][1]);
                // be += p*table[a][b][3];
                p*=table[a][b][3];
                a = b; b = 3;
                // cout<<"p监控"<<p<<endl;
            }
        }
        // cout<<"p监控:"<<p<<endl;
        // cout<<"be:  "<<be<<endl;
    }
    cout<<"译码结果为:"<<t<<endl;
}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    Init();
    cout<<"请输入需要编码的字符序列(编码符号为a,b,c):"<<endl;
    // cout<<table[1][1][1]<<endl;
    while(cin>>s&&s[0]!='#'){
        encord();
        decord();
        // cout<< ((s<t)||(s>t)) == 0?"恭喜你,译码和源码完全一样哦":"Sorry,可能长度超出了默认精度范围了哦,有空试试高精度吧" <<endl; // 不等于输出1
/*        // 经过研究发现，长度变长的时候会出现不相等的情况，分析得知，是因为算法本身的概率选取的调整问题double tp = 0.01*be + 0.99*end;
        // 选取时应该把tp调整到大区间段(个人猜测，不会证明，但可以写一个循环自动化调参训练...当在某个长度(input)上面达到某个精度的时候输出参数)
        // input : length  先建立 length 长的全 a 序列, length重循环  最后一个从 a+0到+1到+2(最内层),每个外层一变化都要变化一次,O(3^length)指数爆炸
        for(double i=0.01;i<1.00;i+=0.01){
            for()// length重for3循环，后面计算  sumOf((s<t)||(s>t)) / 3^length  错误率...维护错误率min的i值 看i为多少的时候l错误率最低
        }*/
        string tstr;
        tstr += ((s<t)||(s>t)) == 0 ? "恭喜你,译码和源码完全一样哦":"Sorry,可能长度超出了默认精度范围了哦,有空试试高精度吧";
        cout<<tstr<<"  此时源码长度为: "<<sl<<endl;
        cout<<"\n是否验证下一个字符序列,是则输入,否则输入#:"<<endl;
    }
    return 0;
}