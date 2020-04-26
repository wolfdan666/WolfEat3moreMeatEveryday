/*
2020年4月26日09:59:11 开始，感觉最低复杂度就是O(k*n),
逐一merge前两个肯定不是效率最高的---虽然可能利用上CPP std中的merge

所以最优思想应该是用败者树

2020年4月26日10:08:21 还是直接自己实现一个优先队列选取元素，然后让队列序号和队列元素值绑定，
关于如果队列用完之后，就resize priority_queue --- 感觉不如用multiset香

2020年4月26日10:12:19 开始自己写一下 --- 还是得查一下multiset的用法，好久没用了
这里的注意点是multiset erase单个元素最好用他的迭代器去erase，直接用元素值会删除所以此元素值的东东

写的时候发现，nullptr直接跳过，之后也再也不会操作，因为他们在队列中没有了，那么就没有再添加的可能了

2020年4月26日10:38:02 越来越觉得自己直接构造出新链表就很离谱地使用内存！所以想要steal偷了原来的链表！
哈哈哈，jjhou的内存管理课内化到了思维方式里面了，真好

2020年4月26日10:55:18 一发入魂，爽
执行用时: 44 ms , 在所有C++提交中击败了48.42%的户
内存消耗: 11.5 MB , 在所有C++提交中击败了14, .29%的用户

2020年4月26日10:58:40 看了答案，发现自己的复杂度少算了优先队列的log(k),所以复杂度是O(kn×logk)
交答案发现答案的内存比我用得少？？？！----2020年4月26日11:08:42 搜了一下，发现优先队列是用堆实现的，可能堆比红黑树占用内存少一点点
执行用时: 48 ms,在所有 C++提交中击败了44 .48%的户
内存消耗: 10.6 MB,在所有 C++提交中击败了95.92% 的用户

一个简单题查了资料还花了一个小时，菜！今晚tx的笔试要加油啊
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct classcomp {
    bool operator() (const pair<ListNode *,ListNode *>& lhs, const pair<ListNode *,ListNode *>& rhs) const
    {return lhs.first->val < rhs.first->val;}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listsSize = lists.size();
        multiset<pair<ListNode *,ListNode *>,classcomp> que;
        for(int i=0 ; i < listsSize ; i++){
            if(nullptr != lists[i]){
                que.insert({lists[i],lists[i]->next});
            }
        }

        ListNode* virtualHead = new ListNode(0);
        ListNode* cur = virtualHead;

        while(!que.empty()){
            auto it = que.begin();
            cur->next = it->first;
            cur = cur->next;
            if(it->second != nullptr){
                que.insert({it->second,it->second->next});
            }

            // 记得删除
            que.erase(it);
        }

        cur = virtualHead->next;
        delete virtualHead;

        return cur;
    }
};

class Solution_ans {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){


    return 0;
}