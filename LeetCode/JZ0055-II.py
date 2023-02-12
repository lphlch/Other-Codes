'''
剑指 Offer 55 - II. 平衡二叉树
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

注意：本题与主站 110 题相同
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# every node, left depth and right depth difference <= 1


class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def getDepth(root):
            left_depth = getDepth(root.left) if root.left else 0
            if left_depth == -1:
                return -1
            right_depth = getDepth(root.right) if root.right else 0
            if right_depth == -1:
                return -1

            if abs(left_depth - right_depth) > 1:
                return -1
            else:
                return max(left_depth, right_depth) + 1

        if root is None:
            return True
        else:
            if getDepth(root) == -1:
                return False
            return True
