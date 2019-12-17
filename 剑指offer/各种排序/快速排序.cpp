#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

bool badPartition = 0;

// int data[],int length 等价于 一个 vector<int>
int Partition(int data[],int length,int start,int end){
    if(data == nullptr || length <= 0 || start < 0 || end >= length){
        // throw new std::exception("Invalid Parameters");
        badPartition = 1;
        return 0;
    }

    int index  = random(start,end);
    // swap(&data[index],&data[end]);
    swap(data[index],data[end]);

    // index 比 small 跑得快,把小于end 的放在small 位置
    int small = start - 1;
    for(index = start; index < end; index++){
        if(data[index] < data[end]){
            ++small;
            if(small != index)
                // swap(&data[index],&data[small]);
                swap(data[index],data[small]);
        }
    }

    // 把大于end的第一位和end换个位置
    ++small;
    // swap(&data[small],&data[end]);
    swap(data[small],data[end]);

    return small;
}

void QuickSort(int data[],int length,int start,int end){
    if(start == end) return ;

    int index = Partition(data,length,start,end);
    if(index > start) QuickSort(data,length,start,index-1);
    if(index < end) QuickSort(data,length,index+1,end);
}

int main(){
    int data[10] = {2,4,6,1,3};
    QuickSort(data,5,0,4);
    rep(i,0,4) cout<< data[i] << " "; cout<<endl;
    
    return 0;
}

// output : 1 2 3 4 6 