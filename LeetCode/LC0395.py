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