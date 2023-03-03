'''
103. 二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
'''


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def zigzagLevelOrder(self, root):
        if not root:
            return []
        
        s1=[]
        s2=[root]
        res=[]
        while s1 or s2:
            sub_res=[]
            while s2:
                node = s2.pop()
                sub_res.append(node.val)
                print(node.val)
                
                if node.left:
                    s1.append(node.left)
                if node.right:
                    s1.append(node.right)

            if sub_res:
                res.append(sub_res)
                
            sub_res=[]
            while s1:
                node = s1.pop()
                sub_res.append(node.val)
                print(node.val)

                if node.right:
                    s2.append(node.right)
                if node.left:
                    s2.append(node.left)
            if sub_res:
                res.append(sub_res)

                    
        return res

        
        
a=Solution()

a11=TreeNode(1)
a21=TreeNode(2)
a22=TreeNode(3)
a33=TreeNode(4)
a34=TreeNode(5)

a11.left=a21
a11.right=a22
a21.left=a33
a22.right=a34

print(a.zigzagLevelOrder(a11))
