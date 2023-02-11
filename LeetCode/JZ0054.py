'''
剑指 Offer 54. 二叉搜索树的第k大节点
给定一棵二叉搜索树，请找出其中第 k 大的节点的值。


'''

# mid order traversal
# can be terminate in advance

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:

        res = []

        def dfs(node):
            if not node:
                return
            dfs(node.right)
            res.append(node.val)
            # print(res)
            dfs(node.left)

        dfs(root)
        return res[k-1]
