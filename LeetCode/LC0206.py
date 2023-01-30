'''
206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        def recursion(now, last):
            if not now:
                return last
            res = recursion(now.next, now)
            now.next = last
            return res

        return recursion(head, None)
