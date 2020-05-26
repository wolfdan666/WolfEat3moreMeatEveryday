/*
2020年5月26日15:35:55 看题

不断输出中位数，这就是剑指offer中的中位数题目

左边用小顶堆，右边用大顶对

堆有点忘了怎么写，看看

2020年5月26日16:01:48 交了，竟然wa了
哦，理解错了题意，尴尬___不是只有一个n2....
2020年5月26日16:08:03 又wa了，90.91%...
感觉题目数据可能有点问题，暂时先跳过先
2020年5月26日17:12:01 发现是因为傻逼数据突然来了一个偶数，但是它中位数，还是按 n/2+1的那个位置判断的

---
本文介绍如何使用STL里的heap（堆）算法。第一次接触heap这种数据结构是在大学的数据结构教材上，它是一棵完全二叉树。在STL中，heap是算法的形式提供给我们使用的。包括下面几个函数：

make_heap: 根据指定的迭代器区间以及一个可选的比较函数，来创建一个heap. O(N)

push_heap: 把指定区间的最后一个元素插入到heap中. O(logN)

pop_heap: 弹出heap顶元素, 将其放置于区间末尾. O(logN)

sort_heap：堆排序算法，通常通过反复调用pop_heap来实现. N*O(logN)

C++11加入了两个新成员：

is_heap: 判断给定区间是否是一个heap. O(N)

is_heap_until: 找出区间中第一个不满足heap条件的位置. O(N)

因为heap以算法的形式提供，所以要使用这几个api需要包含 #include <algorithm>
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
int n1,n2;

template <typename T>
class DynamicArray {
   public:
    void Insert(T num) {
        // 偶数个的时候插入大顶堆，奇数个的时候插入小顶堆
        if (((min.size() + max.size()) & 1) == 0) {
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        } else {
            if (min.size() > 0 && min[0] < num) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    T GetMedian() {
        int size = min.size() + max.size();
        // if (size == 0) throw exception("No numbers are available");

        T median = 0;
        if ((size & 1) == 1)
            median = min[0];
        else
            // median = (min[0] + max[0]) / 2;
            median = min[0];


        return median;
    }

   private:
    vector<T> min;
    vector<T> max;
};

int main(){
    n1 = rd();
    DynamicArray<int> mid;
    int tp;
    rep(i,1,n1){
        tp = rd();
        mid.Insert(tp);
    }
    printf("%d\n", mid.GetMedian());

    while(~scanf("%d",&n2)){
        rep(i,1,n2){
            tp = rd();
            mid.Insert(tp);
        }
        printf("%d\n", mid.GetMedian());
    }

    return 0;
}
