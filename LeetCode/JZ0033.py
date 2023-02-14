'''
剑指 Offer 33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
假设输入的数组的任意两个数字都互不相同。

'''

# key: how to divide the array into two parts
# The last element is the root of the tree of a postorder traversal
# Because of the binary search tree, the left subtree is smaller than the root
# So find the first element that is greater than the root, which is the root of the right subtree
# The left subtree is the left part, and the right subtree is the right part


class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:

        if len(postorder) <= 1:
            return True

        root_val = postorder[-1]
        right_start = -1
        for i, val in enumerate(postorder):
            if val > root_val:
                right_start = i
                break

        left_subtree = postorder[:right_start]
        right_subtree = postorder[right_start:-1]
        # print('postorder', postorder)
        # print('root_val', root_val)
        # print('left_subtree', left_subtree)
        # print('right_subtree', right_subtree)
        for val in right_subtree:
            if val < root_val:
                return False

        return self.verifyPostorder(left_subtree) and self.verifyPostorder(right_subtree)
