'''
剑指 Offer 26. 树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。


'''

# only to know the root value is the same at a time
# then check the left and right subtree
# the same idea for the isSubStructure function

# 3 situation to return False
# 1. A is None, which means B has value but A has not
# 2. A.val != B.val
# 3. when starts, A or B is None(Given situation)

# return True when B is None, which means B has no subtree left


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        def recur(A, B):
            if not B:
                return True
            if not A or A.val != B.val:
                return False
            return recur(A.left, B.left) and recur(A.right, B.right)

        if not A or not B:
            return False
        return recur(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
