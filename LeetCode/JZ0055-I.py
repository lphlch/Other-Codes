'''
剑指 Offer 55 - I. 二叉树的深度
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

注意：本题与主站 104 题相同
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        max_level = 0
        s = [(root, 1)]
        while s:
            node, level = s.pop()

            if node.left:
                s.append((node.left, level+1))
            if node.right:
                s.append((node.right, level+1))

            max_level = max(max_level, level)

        return max_level
