'''
3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

'''



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
