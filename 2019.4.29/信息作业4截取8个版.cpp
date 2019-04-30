// 2019年4月29日16:28:15  发现题目没有讲清楚(其实是自己太菜，没想要把20多个进行改进) ... 8 个  分组，其实主要是为了觉得的精度满足
//  其实第三题的条件概率的那个也是可以分组的，把上下文的判断再加一个判断就可以了

// 静下心来再仔细看一遍字串的编译码

// 这种方法只要不溢出string的内存,理论上来说是可以实现无限长编码的
// 网上查了一下，发现string最大4G
// 4GB是单个程序内存寻址的极限，因此也是CString的极限。
// 绝对够你用了(所以一个2K电影的话就分两个string吧,23333)

// 1.当时听到这个改需求的操作心情是有点烦的，
// 2.后面加上机房里面很喧闹，导致自己也没能够在安静的环境下独自思考
// 3.自己昨天没有分成函数模块写，导致了自己改代码改的有点难受，于是花了2个小时改代码
// 对于tp的取值思考::::取[     ]最终区段的左边会因为迭代操作而一直左偏，所以精度不行，所以选最右边的样子
// exp积累:

// 1、 以后一定要函数化模块
// 2、 昨天想到的只是精度问题，只是想着暴力处理扩大精度，却没有思考的扩大精度的本质其实就是分块操作
// (所以分布式+集群真是大道至简，积累成就无限的可能)
// (所以自己要多多积累，坚持ARST打卡，努力，奋斗，让自己成为技术专家的同时过上幸福的生活)

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
string source, ans, t;
int num[26];
int Myhash[26];
char Myhash2[26];
int XNlen;
typedef pair<double, pair<double, double>> Node;
vector<Node> p;

void solve(){
    int len = int(source.length());
    int last = 0,binlast=0;// 一开始没有想到binlast!
    while(len){
        int slen = len >= 8? 8 : len;
        string s = source.substr(last,slen);

        // last += slen;
        // len -= slen;   // 这两个要在最最最后才搞，否则出错
        // string s = source.substr(last,slen);// mdzz 写在这
        cout<<"s:"<<s<<endl;


        p.clear();
        memset(num, 0, sizeof(num));
        memset(Myhash, 0, sizeof(Myhash));
        memset(Myhash2, 0, sizeof(Myhash2));
        int n = (int)s.length();
        for (int i = 0; i < n; i++)
        {
            num[s[i] - 'a']++;
        }

        // Init
        // 先建立通用的概率，然后再进行讨论
        // pair<possibility,<be,end>> + hash[char] = order
        double be = 0, end = 0;
        int k = 0;
        double temd;
        for (int i = 0; i < 26; i++)
        {
            if (num[i])
            { // 不为0说明有值的
                be = end;
                temd = (double)num[i] / n;
                end = be + temd;
                XNlen += ceil(log(1 / temd) / log(2)) * num[i];
                p.pb({temd, {be, end}});
                Myhash[i] = k;
                Myhash2[k] = 'a' + i;
                k++;
            }
        }
        // p的构建好像出了问题，2019年4月28日12:34:18 来测试一下  最后发现没有出错...
        // for (int i = 0; i < (int)p.size();i++){
        //     cout << "p[i].x:" << p[i].x << " p[i].y.x:" << p[i].y.x << " p[i].y.y:" << p[i].y.y << endl;
        // }

        // encode
        double pos = 1;
        be = 0, end = 0;
        for (int i = 0; i < n; i++){
            int tem = Myhash[s[i] - 'a'];
            be += pos * p[tem].y.x;
            // end += pos * p[tem].y.y;  昨天的bug   今天又错了，就是不能这样操作因为可能第一次就有end = 1，可以不维护end,可以的
            pos *= p[tem].x;
            // cout << "tem:" << tem << " p[tem].y.x" << p[tem].y.x << " p[tem].y.y:" <<p[tem].y.y << endl;
            // cout << "be:" << be << " end:" << end << endl;
            // cout << "pos监控: " << pos << endl;
        }
        end = be + pos;
        // cout << "be:" << be << " end:" << end << endl;
        // cout << "pos监控: " << pos << endl;
        int l = ceil(log(1 / pos) / log(2));
        double tp = 0.01 * be + 0.99 * end;


        int tp2;
        // ans.resize(0);
        for (int i = 0; i < l; i++)
        {
            tp *= 2;
            tp2 = (int)tp;
            tp -= tp2;
            ans += char(tp2 + '0');
        }

        cout << "编码结果为: " << ans << endl;
        int sl = int(s.length());
        cout<<"当前串长:"<<sl<<endl;

        // 译码
        cout << "\n译码: " << endl;
        double res = 0.0;
        double w = 0.5;
        for (int i = binlast; i < binlast+ l ; i++, w *= 0.5) // 要用0 1 码长搞出来
        {
            res += w * (ans[i] - '0');
        }

        cout << "译码选取的数字为:" << res << endl;
        pos = 1;
        // t.resize(0);
        be = 0;
        for (int i = 0; i < sl; i++)
        {
            for (int j = 0; j < k; j++)
            {
                // cout << "p[j].y.x:" << pos*p[j].y.x << "p[j].y.y" << pos*p[j].y.y << endl;
                // if (res >= pos * p[j].y.x && res < pos * p[j].y.y)  // mdzz,这个p值会越来越小，所以根本不能用 这样的比较，必须还是要和be和end比较    1. 没有借鉴昨天的后果  2. 没有思考清楚参考系的结果
                if (res >= be + pos * p[j].y.x && res < be + pos * p[j].y.y)
                {
                    t += Myhash2[j]; // 这里应该是j对应的反hash
                    be += pos * p[j].y.x;
                    pos *= p[j].x;
                    break;// 不跳出可能再二次迭代出错
                }
            }
        }
        cout<<"中间源码为："<<s<<endl;
        cout<<"中间译码为："<<t.substr(last,slen)<<endl;
        last += slen;
        len -= slen;
        binlast += l;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cout<<"请输入需要编码的字符序列(编码符号为小写哦):"<<endl;
    while(cin>>source&&source[0]!='#') {
        XNlen = 0;

        t.resize(0);
        ans.resize(0);
        solve();
        cout<<"编码为："<<ans<<"\n编码长度是："<<ans.length()<<endl;
        cout<<"译码为:"<<t<<endl;
        // 与香农比较
        cout << "编码长度为: " << l << " 香农编码长度为:" << XNlen << endl;
        if (l < XNlen)
        {
            cout << "WOW,Algorithm Code 果然名不虚传！" << endl;
        }

        string tstr;
        tstr += ((source<t)||(source>t)) == 0 ? "恭喜你,译码和源码完全一样哦":"Sorry,可能长度超出了默认精度范围了哦,有空试试高精度吧";
        cout<<tstr<<"  此时源码长度为: "<<int(source.length())<<endl;
        cout<<"\n是否验证下一个字符序列,是则输入,否则输入#:"<<endl;
    }
    return 0;
}