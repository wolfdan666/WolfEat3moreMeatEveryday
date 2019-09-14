/*
    2019年3月30日19:47:14 开始看题目
    浪 5mins 玩gcp  ssh 的vim ，有颜色 ，但发现g++，gcc不行？
    不想自己思考怎么写啊，GG，所以看tutorial吧
    结果答案有一步看不懂，GG，又看成岱code，看不明白，于是去借鉴众人的code
    惊人地发现所有大佬的做法如出一处，但还是懵逼了
    最最最后直接接google了一个大佬的做法，发现原来如此简单...真大佬
*/

// #include<bits/stdc++.h>
// #define forn(i, n) for (int i = 0; i < int(n); i++)
// using namespace std;

// int getSqr(int x){   // 答案的这一步看得我一脸懵逼
//     int l = sqrt(x);
//     for (int i = -2; i <= 2; ++i)
//         if (l + i >= 0 && (l + i) * (l + i) == x)
//             return l;
//     return -1;
// }

// void solve(){
//     int x;
//     scanf("%d", &x);
//     for (int n = 1; n == 1 || n * n - (n / 2) * (n / 2) <= x; ++n){
//         int lk = n * n - x;
//         if (lk < 0) continue;
//         int sq = getSqr(lk);
//         if (sq <= 0) continue;

//         int k = n / sq;
//         if (k > 0 && n * n - (n / k) * (n / k) == x){
//             printf("%d %d\n", n, k);
//             return;
//         }
//     }

//     puts("-1");
// }

// int main() {
//     int tc;
//     scanf("%d", &tc);
//     forn(i, tc)
//         solve();

//     return 0;
// }


// 上面的是tutorial，这里是众大佬
// #include<bits/stdc++.h>
// int t,x,a,b,f,i;
// int main()
// {
// for (scanf("%d",&t);t--;)
//   {
//   scanf("%d",&x);f=0;
//   for (i=0;i<39999;i++)
//     if ((a=i*i-x)>0)
//       if ((b=sqrt(a))*b==a)
//         if (i/b>i/(b+1))
//           {printf("%d %d\n",i,i/b);f=1;break;}
//   if (!f) puts("-1");
//   }
// }

// 下面是真大佬，有他的截图
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int x;
    scanf("%d", &x);
    ll n, m, flag = 0;
    for (n = 1 ; n <= 100000 ; n ++) {
        ll k = n*n - x;
        if (k <= 0) continue;
        ll tmp = sqrt(k);
        m = n / tmp;
        if (tmp * tmp == k && n*n - (n/m)*(n/m) == x ) {
            flag = 1;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
    else cout << n << ' ' << m << endl;
}


int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}