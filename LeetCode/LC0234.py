"""
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

234. 回文链表

给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        s = []
        while head:
            s.append(head.val)
            head = head.next

        return s == s[::-1]
