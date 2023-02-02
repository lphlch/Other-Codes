'''
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

注意：本题与主站 226 题相同
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# reverse the left and right child of each node


class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return
        self.mirrorTree(root.left)
        self.mirrorTree(root.right)
        
        root.left, root.right = root.right, root.left
        return root