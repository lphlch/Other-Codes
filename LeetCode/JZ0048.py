'''
剑指 Offer 48. 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

注意：本题与主站 3 题相同
'''

# record the max substring length for each string end with s[i]
# check the last char if it is in the substring, if so, update the max length, else, add 1 to the last max length
#
# optimize: use a dict to record the last index of each char


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        if len(s) == 1:
            return 1
        dp = [0]*len(s)
        dp[0] = 1
        dic = {}

        for i, c in enumerate(s):
            index = dic.get(c, -1)
            dic[c] = i
            dp[i] = dp[i-1]+1 if index == -1 or index < i-dp[i-1] else i-index
            # print('\ni, c, index, dp[i]\n', i, c, index, dp[i])
        return max(dp)
