/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路:先算出最长的长度是不现实的，所以直接加吧，模拟
2019年5月2日16:10:54 开始写
2019年5月2日16:42:32 交第一发，wa，过10/1563，奇怪
(前面都是手贱)
执行用时 : 40 ms, 在Add Two Numbers的C++提交中击败了97.53% 的用户
内存消耗 : 10.5 MB, 在Add Two Numbers的C++提交中击败了75.22% 的用户
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p= l1;ListNode* q = l2;
        int cur = (p->val + q->val)%10;
        int jin = (p->val + q->val)/10;
        ListNode* ans = new ListNode(cur);
        ListNode* ansp = ans;
        // while(p->next!=NULL&&p->next!=NULL){// 本位已经加过，看看后面是否还有要加 mdzz 写了两个p 第一发wa的原因(第二又未改,加了这个注释...:(..
        while(p->next!=NULL&&q->next!=NULL){// 本位已经加过，看看后面是否还有要加
            p = p->next,q = q->next;
            cur = (p->val + q->val + jin)%10;
            jin = (p->val + q->val + jin)/10;
            ListNode* u = new ListNode(cur);
            ansp->next = u;
            ansp = u;
        }
        if(p->next==NULL){
            while(q->next!=NULL){
                q = q->next;
                cur = (q->val + jin)%10;
                jin = (q->val + jin)/10;
                ListNode* u = new ListNode(cur);
                ansp->next = u;
                ansp = u;
            }
            if(jin){// 这个进位一定是1
                ListNode* u = new ListNode(1);
                ansp->next = u;
                ansp = u;
            }
        }
        else if(q->next==NULL){
            while(p->next!=NULL) {
                p = p->next;
                // cur = (q->val + jin)%10;  //复制粘贴真香，wa的第三p
                // jin = (q->val + jin)/10;
                cur = (p->val + jin)%10;
                jin = (p->val + jin)/10;
                ListNode* u = new ListNode(cur);
                ansp->next = u;
                ansp = u;
            }
            if(jin){// 这个进位一定是1
                ListNode* u = new ListNode(1);
                ansp->next = u;
                ansp = u;
            }
        }
        return ans;
    }
};