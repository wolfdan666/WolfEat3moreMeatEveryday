/*
2020年6月12日19:57:03 开始想题
conor case :  k == 1
 k == 2 待定
然后pre = null, cur = head(判nullptr), nxt = cur->next(判nullptr)

op:
1. cur->next指向pre
2. pre = cur
3. cur = nxt
4. nxt = nxt->next (判nullptr)

2020年6月12日20:27:49 测试一下，有点问题，淡定
2020年6月12日20:34:07 发现head_to_tail指早了

2020年6月12日20:55:25 还是没写出来，有点尴尬，问题不大，继续写，多练

2020年6月12日21:15:51 WA了，因为后面如果长度不够的话，不用交换！|

2020年6月12日21:25:13 终于AC
执行用时: 20 ms,在所有 C++提交中击败了86.28% 的用户
内存消耗: 8.9 MB , 在所有C++提交中击败了100.00% 的户

1小时28分钟，自己太菜了

2020年6月12日21:33:01 看到别人递归思路这么清晰，自己哭了，继续练习吧
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

class Solution {
public:
    bool check_goon(ListNode* curHead,int k){
        ListNode* tmp_check = curHead;
        int tmp_cnt = 0;
        while(tmp_check!=nullptr){
            tmp_cnt++;
            if(tmp_cnt == k){
                tmp_cnt = 0;
                return true;
            }
            tmp_check=tmp_check->next;
        }
        return false;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        if(1 == k) return head;

        // 前面已经确保了有两个元素
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        ListNode* head_to_tail = cur;
        ListNode* ans_pre = new ListNode(0);
        ListNode* pre_head_to_tail = ans_pre;

        int cnt = 0;
        // 题目保证了，所以第一轮不用check

        while(cur != nullptr){
            cur->next = pre;

            // 上一轮的新尾的next要指向这一轮的新头
            pre_head_to_tail->next = cur;

            pre = cur;
            cur = nxt;
            // nxt->next 可以nullptr, 但nxt不行
            if(nxt != nullptr) nxt = nxt->next;

            cnt = (cnt+1) % k;
            // 这个时候是cur指向了最后一个翻转，要重新开始就要向后一位
            if(cnt == 0){
                pre = nullptr;
                // 上一轮的新尾的next要指向这一轮的新头
                // 然后更替
                // pre_head_to_tail->next = cur;
                pre_head_to_tail = head_to_tail;

                // 2020年6月12日21:14:08 仔细分析，其实cur已经在下一轮k 的开始位置了
                // 不用nxt!
                // cur = nxt;

                if(cur == nullptr) break;
                // 记录新的头变尾
                head_to_tail = cur;

                // 2020年6月12日21:14:47 cur不用nxt，这里也不用
                // if(nxt != nullptr) nxt = nxt->next;

                if(check_goon(cur,k) == false){
                    // 上一轮的新尾的next要指向这一轮的新头
                    pre_head_to_tail->next = cur;
                    break;
                }
            }
        }



        ListNode* ans = ans_pre->next;
        delete ans_pre;
        return ans;
    }
};


/*

执行用时: 28 ms , 在所有C++提交中击败了51.11% 的用户
内存消耗: 8.9 MB , 在所有C++提交中击败了100.00% 的户

递归简洁，但是慢一点点，但是面试要快，所以还是写递归好点
*/

class Solution2 {
public:
    ListNode* reverseKGroup(struct ListNode* head, int k){
        struct ListNode* ptrEnd;
        struct ListNode* ptrStart;
        struct ListNode* ptrCurr;
        if(head == NULL) return NULL;
        int i = 0;
        ptrCurr = head;
        for(i = 0; i < k; i++)//判断是否应该直接返回   (数组长度<k)
        {
            if(ptrCurr != NULL)
            {
                ptrCurr = ptrCurr->next;
            }
            else
            {
                return head; //遇到null了，说明数组短，直接返回
            }
        }
        ptrStart = head;
        ptrEnd = ptrStart;
        ptrCurr = ptrStart->next;
        //翻转过程 注意 只进行k-1次翻转 考虑把两个数反过来，只需要进行一次操作  k个数就是k-1次操作
        for(i = 1; i < k; i++)
        {
            if(ptrCurr)
            {
                ptrEnd->next = ptrCurr->next;
                ptrCurr->next = ptrStart;
                ptrStart = ptrCurr;
                ptrCurr = ptrEnd->next;
            }
        }
        ptrEnd->next = reverseKGroup(ptrCurr,k);//递归 看起来还是挺简洁的
        return ptrStart;
    }
};

// 作者：innsd
// 链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/cyu-yan-shi-xian-fan-zhuan-lian-biao-by-innsd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){
    Solution test;
    ListNode head(1);
    ListNode* pre = &head;
    rep(i,2,5){
        ListNode* tmp = new ListNode(i);
        pre->next = tmp;
        pre = tmp;
    }

    ListNode* ans = &head;
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    puts("");


    // ans = test.reverseKGroup(&head,2);
    ans = test.reverseKGroup(&head,3);

    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    puts("");


    return 0;
}