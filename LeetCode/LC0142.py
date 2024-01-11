"""
142. Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        quick_point = head
        slow_point = head

        while quick_point and quick_point.next:
            quick_point = quick_point.next.next
            slow_point = slow_point.next

            if quick_point == slow_point:
                # assume the cycle starts at point a, cycle has the length of b
                # when they meet, quick = 2*slow = slow + nb (n is the number of loops)
                # so quick = 2nb, slow = nb
                # let the quick back to head, and move both quick and slow one step each time
                # when they meet again, quick = a, slow = a + nb
                # so they meet at the start of the cycle
                quick_point = head

                while quick_point != slow_point:
                    quick_point = quick_point.next
                    slow_point = slow_point.next

                return quick_point

        return None
