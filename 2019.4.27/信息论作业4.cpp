/*
设信源可能输出的符号是26个字母，且每个字母出现的概率未知，试编写程序可以对任意字母序列
（如presentation）进行完全统计模型的算术编码，并与香农编码进行码长比较（比值）。
2019年4月28日00:10:34 写点思路睡觉，这个应该简单
2019年4月28日08:34:50 focus
//  GG了，8点到10点，还是没有清完bug去验收
*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
string s,ans,t;
int num[26];
int Myhash[26];
int XNlen;
typedef pair<double,pair<double,double> > Node;
vector<Node> p;

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    while(cin>>s){
        XNlen = 0;
        memset(num,0,sizeof(num));
        int n = (int)s.length();
        for(int i=0;i<n;i++){
            num[s[i]-'a']++;
        }

        // Init
        // 先建立通用的概率，然后再进行讨论
        // pair<possibility,<be,end>> + hash[char] = order
        double be=0,end=0;
        int k = 0;double temd;
        for(int i=0;i<26;i++){
            if(num[i]){ // 不为0说明有值的
                be = end;
                temd = (double)num[i]/n;
                end = be + temd;
                XNlen += ceil(log(1/temd)/log(2))*num[i];
                p.pb({k,{be,end}});
                Myhash[s[i]-'a'] = k;
                //在vscode debug结果令人震惊的时候还是得手动
                // cout<<"be: "<<be<<" end: "<<end<<endl;
                k++;
            }
        }
        // cout<<setprecision(10)<<"first:"<<p[k-1].y.x<<" second:"<<p[k-1].y.y<<end;// 测试是否为1,为什么得出的是11？   // 因为手贱把endl写成了end


        // encode
        double pos = 1;be = 0,end = 0;
        for(int i=0;i<n;i++){//  其实自己在初始化的时候k值和p的下标值重复了，所以浪费了存储，暂时不改先吧// 直接改成end - begin (那把之前所有用到这里的地方统一改一下，避免新的错误)
            int tem = Myhash[s[i]-'a'];
            be += pos*p[tem].y.x;
            end += pos*p[tem].y.y;
            pos *= p[tem].x;
        }
        int l = ceil(log(1/pos)/log(2));
        double tp = 0.5*be + 0.5*end;
        int tp2;
        ans.resize(0);
        for(int i=0;i<l;i++){
            tp *= 2;
            tp2 = (int)tp;
            tp -= tp2;
            ans += char(tp2+'0');
        }
        cout<<"编码长度为: "<<l<<" 香农编码长度为:"<<XNlen<<endl;
        if(l<XNlen){
            cout<<"WOW,Algorithm Code 果然名不虚传！"<<endl;
        }
        cout<<"编码结果为: "<<ans<<endl;
        int sl = int(s.length());


        // 译码
        cout<<"译码: "<<endl;
        double res = 0.0;double w = 0.5;
        for(int i=0;i<l;i++,w*=0.5){
            res += w*(ans[i]-'0');
        }
        cout<<"译码选取的数字为:"<<res<<endl;
        pos = 1;
        t.resize(0);
        for(int i=0;i<sl;i++){
            for(int j=0;j<k;j++){
                if(res>=pos*p[j].y.x&&res<pos*p[j].y.y){
                    t += ('a'+j);
                    pos *= p[j].x;
                }
            }
        }
        cout<<"译码结果为: "<<t<<endl;
    }

    return 0;
}