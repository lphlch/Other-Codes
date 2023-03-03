'''
440. 字典序的第K小数字
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

440. K-th Smallest in Lexicographical Order
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
'''

# n is too large, so we can't use sort to solve this problem
# class Solution:
#     def findKthNumber(self, n: int, k: int) -> int:

#         l = [i for i in range(1, n+1)]

#         l.sort(key=str)
#         return l[k-1]

# 前缀树
# 当 k 在前缀树的当前结点内，向下
# 不在，向右
# 计算当前结点树的子节点数量即可与 k 比较


class Solution:

    def findKthNumber(self, n: int, k: int) -> int:
        def countNode(curr, max_n):
            count = 0
            next = curr + 1
            while curr <= max_n:
                count += min(max_n+1, next) - curr
                curr *= 10
                next *= 10

            return count

        res = 1
        node_count = 1
        while node_count < k:
            # 计算子节点数量
            node_num = countNode(res, n)
            print(node_count, node_num, res)
            if node_count+node_num > k and res * 10 <= n:
                node_count = node_count+1
                res = res*10
            else:
                node_count = node_count+node_num
                res = res + 1

        return res


a = Solution()
print(a.findKthNumber(11, 1))
