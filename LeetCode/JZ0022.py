'''
剑指 Offer 22. 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。
为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
'''

# key: how to locate the position of the last kth node

# Method 1
# get the length of the list, then go n-k steps

# Method 2
# use two pointers
# one pointer goes k steps first
# then move both pointer until the first pointer reaches the end


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        curr = head
        n = 0
        while curr.next:
            n = n+1
            curr = curr.next

        for i in range(n-k+1):
            head = head.next

        return head
