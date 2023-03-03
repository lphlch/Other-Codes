'''
25. K 个一组翻转链表
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？

25. Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Follow-up: Can you solve the problem in O(1) extra memory space?

'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
#         s = []
#         count = 0
#         start = head
#         start_flag = True
#         prev = head
#         node = None
#         while head:
#             s.append(head)
#             head = head.next
#             count += 1
#             if count == k:
#                 next = head

#                 prev.next = s[-1]
#                 if start_flag:
#                     start = s[-1]
#                     start_flag = False

#                 while s:
#                     node = s.pop()
#                     node.next = s[-1] if s else next

#                 count = 0
#                 prev = node

#         return start


# Follow - up:

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
            if not head:
                return None
            ori_head = head
            prev = head
            head = head.next
            prev.next = None
            next = None
            while head:
                next = head.next
                head.next = prev
                prev = head
                head = next

            print(prev.val, ori_head.val)
            return prev, ori_head

        count = 0
        start = ListNode(-1)
        start.next = head
        prev = start
        while head:
            count += 1
            head = head.next
            print(count, head.val if head else None)
            if count == k:
                next = head
                head.next = None
                print('reverse')
                begin, end = reverseList(self, prev.next)
                
                print(prev.val, begin.val, end.val, next.val)
                
                prev.next = begin
                end.next = next

                count = 0
                prev = end
                head = next
                print(prev.val, head.val)
                

        return start.next
