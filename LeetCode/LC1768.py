'''
1768. 交替合并字符串
给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。

返回 合并后的字符串 。

1768. Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 
'''


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res_string = ""

        n = min(len(word1),len(word2))

        for i in range(n):
            res_string = res_string + word1[i] + word2[i]

        res_string = res_string + word1[n:] + word2[n:]
        

        return res_string

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return ''.join(a + b for a, b in zip_longest(word1, word2, fillvalue=''))

