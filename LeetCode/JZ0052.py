'''
剑指 Offer 52. 两个链表的第一个公共节点
输入两个链表，找出它们的第一个公共节点。

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
本题与主站 160 题相同

'''

# Considered that len(a) + len(b) is a constant
# So we can use two pointers to traverse the two lists
# one from a to b, the other from b to a
# when the two pointers meet, the node is the intersection node

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        pointA = headA
        pointB = headB

        if pointA == None or pointB == None:
            return None
        
        endCount = 0

        while endCount < 3:
            if pointA == pointB:
                return pointA

            if pointA.next == None:
                pointA = headB
                endCount += 1
            else:
                pointA = pointA.next

            if pointB.next == None:
                pointB = headA
                endCount += 1
            else:
                pointB = pointB.next

        return None
