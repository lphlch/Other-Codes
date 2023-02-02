'''
101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。

101. Symmetric Tree
Given the root of a binary tree
check whether it is a mirror of itself (i.e., symmetric around its center).

'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        q = [root]
        while q:
            res = []
            for _ in range(len(q)):
                node = q.pop(0)
                if node:
                    res.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
                else:
                    res.append(None)
            if res != res[::-1]:
                return False
        return True
