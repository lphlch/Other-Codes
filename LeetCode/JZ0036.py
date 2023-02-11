'''

剑指 Offer 36. 二叉搜索树与双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。
特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
'''


"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

# middle order traversal and link the nodes


class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':

        def dfs(node):
            if not node:
                return

            dfs(node.left)

            # print('node', node.val)
            # print('pre', self.pre.val)

            if self.pre:
                self.pre.right = node
                node.left = self.pre
            else:
                self.head = node

            self.pre = node

            dfs(node.right)

        self.pre = None
        if not root:
            return None
        
        dfs(root)
        self.head.left, self.pre.right = self.pre, self.head

        return self.head
