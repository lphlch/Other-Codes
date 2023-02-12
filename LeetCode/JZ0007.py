'''
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

注意：本题与主站 105 题重复
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        def buildSubTree(preorder, inorder):
            if len(preorder) <= 1:
                return TreeNode(preorder[0])

            mid_value = preorder[0]
            mid_index = inorder.index(mid_value)
            left = inorder[:mid_index] if mid_index > 0 else []
            right = inorder[mid_index+1:] if mid_index < len(inorder)-1 else []

            root = TreeNode(mid_value)

            # build left and right subTree
            root.left = buildSubTree(
                preorder[1:mid_index+1], left) if left else None
            root.right = buildSubTree(
                preorder[mid_index+1:], right) if right else None

            return root

        if not preorder:
            return None

        return buildSubTree(preorder, inorder)
