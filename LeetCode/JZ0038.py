'''
剑指 Offer 38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

'''


class Solution:
    def permutation(self, s: str):

        def recur(curr, remain):
            if len(remain) == 1:
                return curr + remain

            sub_res = []
            for c in set(remain):
                sub_res.append(recur(curr+c, remain.replace(c, '', 1)))

            return ','.join(sub_res)

        return recur('', s).split(',')


a = Solution()
print(a.permutation('aabb'))
