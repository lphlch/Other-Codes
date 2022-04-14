'''
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
'''


class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        if l < 2:
            return s

        dp = [[0]*l for i in range(l)]
        
        for i in range(l):
            dp[i][i] = 1

        left = 0
        maxLength = 0

        for length in range(2, l+1):
            for i in range(l):
                j = i+length-1
                if j > l-1:
                    break

                if s[i] != s[j]:
                    dp[i][j] = 0
                else:
                    if length < 3:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = dp[i+1][j-1]

                if dp[i][j] and length > maxLength:
                    maxLength = length
                    left = i

        if maxLength == 0:
            return s[0]
        return s[left:left+maxLength]
