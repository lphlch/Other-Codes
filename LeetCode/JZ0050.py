'''
剑指 Offer 50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符
如果没有，返回一个单空格
s 只包含小写字母。


'''

# dict is ordered in python3.6


class Solution:
    def firstUniqChar(self, s: str) -> str:
        dict = {}
        for c in s:
            dict[c] = dict.get(c, 0) + 1

        for key, value in dict.items():
            if value == 1:
                return key

        return ' '
