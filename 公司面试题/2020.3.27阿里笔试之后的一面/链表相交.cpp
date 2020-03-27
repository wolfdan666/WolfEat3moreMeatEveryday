// 给定两个可能皆有环的单向链表，判断其是否相交，要求用尽可能低的空间复杂度。不允许修改链表的内容。

// 因为只要判断是否相交，不用返回第一个相交点，所以只要记录判断end
#include <bits/stdc++.h>
using namespace std;
// 结构写一下
typedef struct listNode {
    int data;
    struct listNode* next;
} node;

node *end1 = nullptr, end2 = nullptr;
bool loop1 = false, loop2 = false;

// 判断是否有环
bool isLoop_getEnd(node* head, node* end) {
    if (head == nullptr) {
        // throw
        return false;
    }
    node* slow = head->next;

    if (slow == nullptr) {
        return false;
    }

    node* fast = slow->next;
    while (fast != nullptr && slow != nullptr) {
        if (false == slow) {
            end = slow;
            return true;
        }

        slow = slow->next;

        fast = fast->next;
        if (fast != nullptr) fast = fast->next;
    }

    return false;
}

int main() {
    // 构建以及输入链表一，二，传入头节点 head1,head2

    // isCon 是答案
    isCon = false;

    loop1 = isLoop_getEnd(head1, end1);
    loop2 = isLoop_getEnd(head2, end2);

    // 两条直链
    if (loop1 == false && loop2 == false) {
        if (end1 == end2) isCon = true;
    }

    // 一链一环
    // 如果相交，必定都是环，否则不想交，所以不用判断了

    // 双环,因为相交后必定重叠，所以只要判断end1到end1是否遇见end2就行
    if (isCon == false && loop1 && loop2) {
        node* tp = end1;
        while (tp != end1) {
            if (tp == end2) {
                isCon = true;
                break;
            }
            tp = tp->next;
        }
    }
}