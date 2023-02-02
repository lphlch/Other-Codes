'''
剑指 Offer 32 - II. 从上到下打印二叉树 II
从上到下按层打印二叉树
同一层的节点按从左到右的顺序打印，每一层打印到一行。

注意：本题与主站 102 题相同
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            tmp=[]
            for _ in range(len(queue)):
                node = queue.pop(0)
                tmp.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(tmp)
        return res