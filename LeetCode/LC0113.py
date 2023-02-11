'''
113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
'''

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