'''
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

'''

# Method 1:
# use replace (very easy)

# Method 2:
# how to move the string? -> copy


class Solution:
    def replaceSpace(self, s: str) -> str:
        ss = ''
        for i in s:
            if i == ' ':
                ss += '%20'
            else:
                ss += i

        return ss
