'''
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def rec(root):
            res = []
            if not root:
                return []
            res.append(root.val)
            res = res + rec(root.left)

            res = res + rec(root.right)
            return res

        node = root

        return rec(node)
