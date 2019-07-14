
# 2019年7月12日01:09:29
# 链表题目核心--> 中间变量存要换掉的链路，思路跟着新建的链路走


class Solution:
    # 题目是要奇偶节点交换
    def swapPairs(self, head: ListNode) -> ListNode:
        pre,pre.next = self,head
        # 1,2存在
        while pre.next and pre.next.next:
            # a是1号,b是2号
            #然后把a.next指向3号(b.next),再给pre到a, pre.next 指向2号,
            a = pre.next
            b = a.next
            # 这TM是秀技术代码吗，看了好久没看懂
            # pre.next 先指向三号，也就是当前节点变更，然后就是

            # 2019年7月12日00:26:06做完今天的健身再回来看，发现很简单(**重点之前没有用顺序看python的赋值**)
            # 首先让pre(一开始是self).next = b(2号);然后让b.next=a(与前面串起来成为self->2->1)
            # 然后让a.next(a已经被b串起来乐)指向3,在最后制定新的pre = a,就可以进入循环了(此时pre.next是3号,pre.next.next是4号)


            pre.next,b.next,a.next = b,a,b.next
            pre = a
        return self.next