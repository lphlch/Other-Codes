'''
144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

144. Binary Tree Preorder Traversal
Given the root of a binary tree, return the preorder traversal of its nodes' vals.

'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        def pre(root, result):
            if not root:
                return result

            result.append(root.val)
            result = pre(root.left, result)
            result = pre(root.right, result)
            return result

        result = []
        result = pre(root, result)

        return result


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        s = [root]

        result = []
        while s:
            node = s.pop()
            if node:
                result.append(node.val)
                s.append(node.right)  # ! right first as stack used
                s.append(node.left)

        return result
