'''
剑指 Offer 34. 二叉树中和为某一值的路径
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

注意：本题与主站 113 题相同
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        res = []
        if not root:
            return res
        s = [(root, root.val, [root.val])]
        while s:
            node, val,path = s.pop()
            if node.left:
                s.append((node.left, val + node.left.val,
                         path + [node.left.val]))
            if node.right:
                s.append((node.right, val + node.right.val,
                         path + [node.right.val]))
            if not node.left and not node.right:
                if val == target:
                    res.append(path)

        return res
