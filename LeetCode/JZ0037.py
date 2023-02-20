'''
剑指 Offer 37. 序列化二叉树
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

注意：本题与主站 297 题相同
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        s = [root]
        res = ""
        while s:
            node = s.pop()
            node_val = str(node.val)
            # print(node_val)

            if node.left:
                node_val = node_val + '|&'
            else:
                node_val = node_val + '|#'
            if node.right:
                node_val = node_val + '|&'
            else:
                node_val = node_val + '|#'
            if node.right:
                s.append(node.right)
            if node.left:
                s.append(node.left)
            res = res+','+node_val
        # print(str(res))
        return str(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data == "":
            return None
        root_all = TreeNode()
        nodes = data[1:].split(',')
        # print('nodes',nodes)
        s = [root_all]
        index = 0
        while s:
            root = s.pop()
            root_node = nodes[index].split('|')
            # print(root_node)
            root.val = int(root_node[0])

            if root_node[2] == '&':
                root.right = TreeNode()
                s.append(root.right)
            if root_node[1] == '&':
                root.left = TreeNode()
                s.append(root.left)

            index += 1

        return root_all


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
