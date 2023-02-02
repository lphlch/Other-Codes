'''
请实现一个函数，用来判断一棵二叉树是不是对称的
如果一棵二叉树和它的镜像一样，那么它是对称的。

注意：本题与主站 101 题相同
'''

# level traverse, compare every level


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        q = [root]
        while q:
            res = []
            for _ in range(len(q)):
                node = q.pop(0)
                if node:
                    res.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
                else:
                    res.append(None)
            if res != res[::-1]:
                return False
        return True
