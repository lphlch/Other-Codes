'''
剑指 Offer 24. 反转链表
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

本题与主站 206 题相同
'''

# change the link when recursion ends


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def recursion(now, last):
            if not now:
                return last
            res = recursion(now.next, now)
            now.next = last
            return res

        return recursion(head, None)
