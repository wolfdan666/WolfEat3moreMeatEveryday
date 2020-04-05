/*
2020年4月5日21:10:12 想了20分钟还是没有什么思路..
看答案吧

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/
来源：力扣（LeetCode）

2020年4月5日21:46:51 交了
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

// 方法一: 利用了set<Node>有序的特性
// struct Node {
//     int cnt, time, key, value;

//     Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}

//     bool operator < (const Node& rhs) const {
//         return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
//     }
// };
// class LFUCache {
//     // 缓存容量，时间戳
//     int capacity, time;
//     unordered_map<int, Node> key_table;
//     set<Node> S;
// public:
//     LFUCache(int _capacity) {
//         capacity = _capacity;
//         time = 0;
//         key_table.clear();
//         S.clear();
//     }

//     int get(int key) {
//         if (capacity == 0) return -1;
//         auto it = key_table.find(key);
//         // 如果哈希表中没有键 key，返回 -1
//         if (it == key_table.end()) return -1;
//         // 从哈希表中得到旧的缓存
//         Node cache = it -> second;
//         // 从平衡二叉树中删除旧的缓存
//         S.erase(cache);
//         // 将旧缓存更新
//         cache.cnt += 1;
//         cache.time = ++time;
//         // 将新缓存重新放入哈希表和平衡二叉树中
//         S.insert(cache);
//         it -> second = cache;
//         return cache.value;
//     }

//     void put(int key, int value) {
//         if (capacity == 0) return;
//         auto it = key_table.find(key);
//         if (it == key_table.end()) {
//             // 如果到达缓存容量上限
//             if (key_table.size() == capacity) {
//                 // 从哈希表和平衡二叉树中删除最近最少使用的缓存
//                 key_table.erase(S.begin() -> key);
//                 S.erase(S.begin());
//             }
//             // 创建新的缓存
//             Node cache = Node(1, ++time, key, value);
//             // 将新缓存放入哈希表和平衡二叉树中
//             key_table.insert(make_pair(key, cache));
//             S.insert(cache);
//         }
//         else {
//             // 这里和 get() 函数类似
//             Node cache = it -> second;
//             S.erase(cache);
//             cache.cnt += 1;
//             cache.time = ++time;
//             cache.value = value;
//             S.insert(cache);
//             it -> second = cache;
//         }
//     }
// };



// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){


    return 0;
}