/*
设信源可能输出的符号是26个字母，且每个字母出现的概率未知，试编写程序可以对任意字母序列
（如presentation）进行完全统计模型的算术编码，并与香农编码进行码长比较（比值）。
2019年4月28日00:10:34 写点思路睡觉，这个应该简单
2019年4月28日08:34:50 focus
//  GG了，8点到10点，还是没有清完bug去验收
// 没有上体育课，然后自己就在这里边怂恿倩倩姐姐给我注册GCP一边debug，又浪了90mins，快去吃饭2019年4月28日11:55:42

2019年4月28日19:44:50 总算找完了bug，发现真的有精度问题，如果p后面变得很小的时候，那判断的时候很可能去掉几位判断
最近这几天事情比较多，所以就不写高精度的小数计算了
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
string s, ans, t;
int num[26];
int Myhash[26];
char Myhash2[26];
int XNlen;
typedef pair<double, pair<double, double>> Node;
vector<Node> p;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    while (cin >> s)
    {
        XNlen = 0;
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
                // p.pb({k, {be, end}});
                Myhash[i] = k;
                Myhash2[k] = 'a' + i;
                // Myhash['a' + i] = k;
                // Myhash[s[i] - 'a'] = k;
                //在vscode debug结果令人震惊的时候还是得手动
                // cout<<"be: "<<be<<" end: "<<end<<endl;
                k++;
            }
        }
        // cout<<setprecision(10)<<"first:"<<p[k-1].y.x<<" second:"<<p[k-1].y.y<<end;// 测试是否为1,为什么得出的是11？   // 因为手贱把endl写成了end

        // p的构建好像出了问题，2019年4月28日12:34:18 来测试一下  最后发现没有出错...
        // for (int i = 0; i < (int)p.size();i++){
        //     cout << "p[i].x:" << p[i].x << " p[i].y.x:" << p[i].y.x << " p[i].y.y:" << p[i].y.y << endl;
        // }

        // encode
        double pos = 1;
        be = 0, end = 0;
        for (int i = 0; i < n; i++)
        { //  其实自己在初始化的时候k值和p的下标值重复了，所以浪费了存储，暂时不改先吧// 直接改成end - begin (那把之前所有用到这里的地方统一改一下，避免新的错误)
            // int tem = Myhash[int(s[i])]; 全都对应着上面的改动
            // 2019年4月28日12:52:03发现了错误根源，又是因为自己没有整体构思，而是边写边改，导致出错，这里是因为p.pb那里没有跟着改动而改动
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
        double tp = 0.5 * be + 0.5 * end;
        int tp2;
        ans.resize(0);
        for (int i = 0; i < l; i++)
        {
            tp *= 2;
            tp2 = (int)tp;
            tp -= tp2;
            ans += char(tp2 + '0');
        }
        cout << "编码长度为: " << l << " 香农编码长度为:" << XNlen << endl;
        if (l < XNlen)
        {
            cout << "WOW,Algorithm Code 果然名不虚传！" << endl;
        }
        cout << "编码结果为: " << ans << endl;
        int sl = int(s.length());

        // 译码
        // 2019年4月28日13:06:19 发现译码有问题
        cout << "译码: " << endl;
        double res = 0.0;
        double w = 0.5;
        for (int i = 0; i < l; i++, w *= 0.5)
        {
            res += w * (ans[i] - '0');
        }
        cout << "译码选取的数字为:" << res << endl;
        pos = 1;
        t.resize(0);
        // 译码长度可能和源码不同，说明译码有错，先睡觉吧
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
        cout << "译码结果为: \n" << t << endl;
    }

    return 0;
}