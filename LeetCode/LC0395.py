'''
395. Longest Substring with At Least K Repeating Characters
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

395. 至少有 K 个重复字符的最长子串
给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
'''
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if(len(s) < k):
            return 0

        for ch in set(s):   # set means no duplicate
            if(s.count(ch) < k):
                # split string by ch, and ch will not appear in set
                subStrings = s.split(ch)
                maxLen = 0
                for subString in subStrings:
                   maxLen = max(self.longestSubstring(subString, k), maxLen)
                return maxLen
        return len(s)