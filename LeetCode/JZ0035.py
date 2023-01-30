'''
剑指 Offer 35. 复杂链表的复制
请实现 copyRandomList 函数，复制一个复杂链表
。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点
还有一个 random 指针指向链表中的任意节点或者 null。

本题与主站 138 题相同
'''


# Definition for a Node.
# class Node:
#     def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
#         self.val = int(x)
#         self.next = next
#         self.random = random

# Key: how to know the new node address?

# Method 1: map
# record a map of old node to new node, then rebuild the link
# how to know the new node address? -> use map

# Method 2: follow the old node
# for each old node, create a new node and insert it after the old node, then split the two list
# how to know the new node address? -> just follow the old node

class Solution:
    def copyRandomList(self, head):
        old_to_new = {}
        curr = head
        while curr:
            new_node = Node(curr.val)
            old_to_new[curr] = new_node
            curr = curr.next

        curr = head
        while curr:
            old_to_new[curr].next = old_to_new[curr.next] if curr.next else None
            old_to_new[curr].random = old_to_new[curr.random] if curr.random else None
            curr = curr.next

        # print(old_to_new)
        # while head:
        #     print(head.val, head.next.val if head.next else None, head.random.val if head.random else None)
        #     head = head.next

        return old_to_new[head] if head else None
