class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur,prev = head,None
        while cur:
            # cur.next 可以看做是反转链表的下一个(形成连接关系), prev 可以看做是反转链表的当前值,  而cur = cur.next就是遍历的中间变量
            cur.next,prev,cur = prev,cur,cur.next
        return prev