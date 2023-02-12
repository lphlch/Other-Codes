'''
236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 
'''

'''
剑指 Offer 68 - II. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”


注意：本题与主站 236 题相同

'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# Key: how to locate the common ancestor node

# Method 1: find the path from root to p and q, then compare the path

# Method 2: find the path, when backtracking, return a flag which mark the node is at this side
# if two marks are different, then the node is the common ancestor
# if only one mark returned, return the mark as its return value

# class Solution:
#     def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
#         def getPath(root, target):
#             s = [(root, [])]

#             while s:
#                 node, path = s.pop()
#                 if node == target:
#                     return path + [node]
#                 else:
#                     if node.left:
#                         s.append((node.left, path + [node]))
#                     if node.right:
#                         s.append((node.right, path + [node]))

#         p_path = getPath(root, p)
#         q_path = getPath(root, q)

#         length = min(len(p_path), len(q_path))
#         for i in range(length):
#             if p_path[i] != q_path[i]:
#                 return p_path[i-1]
#         return p_path[length-1] if len(p_path) < len(q_path) else q_path[length-1]


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def recur(root):
            left = right = None
            if not root:
                return False
            if root == p or root == q:
                return root

            if root.left:
                left = recur(root.left)
            if root.right:
                right = recur(root.right)

            if left and right:
                return root
            else:
                return left if left else right

        return recur(root)
