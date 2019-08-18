/*直接行列序列化排序的做法,真滴是好想法!*/

/*2019年8月18日20:26:30 发现这是一个假做法！靠着数据水才过的！因为这里只比较了最大的3个
行值，就去比较列值了！

因为可能有一种情况就是选第4大行，但是取到的列值更多，这应该是有可能出现的，
总之这种做法虽然能过   但是是有可能遗漏情况的假算法！

必须要枚举到所有的行
*/
#include<bits/stdc++.h>
using namespace std;
const int M =1e5 + 10;
int num[M *3];
int  n , r , ans;
int cnt[M * 3];
struct node{
    int x , y;
    int id;
    bool operator<(node d)const{
        return x > d.x;
    }
}a[M] , b[M];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >>r;
    for(int i =1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].x++;
        a[i].y++;
        num[a[i].x]++;
    }
    /*枚举每个行坐标,相加从上到下3行的值-->二维降到一维*/
    for(int i = 1;i <= 100000;i++){
        /*之所以放在最左边是因为i是从最左边开始,免去判断*/
        b[i].x = num[i] + num[i +r] + num[i +r +r];
        b[i].id = i;
    }
    /*行值获利大到小排序*/
    sort(b + 1 ,b + 100001);
    for(int i = 1;i <= 3;i++){
        memset(cnt , 0 ,sizeof(cnt));
        for(int j = 1;j <= n;j++){
            /*除去原来的行(3次行值取max)以外的其他列的值的统计*/
            if(a[j].x != b[i].id && a[j].x != b[i].id +r  && a[j].x != b[i].id +r * 2) cnt[a[j].y]++;
        }
        int sum = 0;
        for(int j = 1; j < M;j++) sum = max( sum , cnt[j] + cnt[j +r] +cnt[j + r + r]);
        ans = max(ans , sum + b[i].x);
    }
    cout << ans <<endl;
}