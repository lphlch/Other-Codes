'''
剑指 Offer 59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
你可以假设 k 总是有效的，在输入数组 不为空 的情况下，1 ≤ k ≤ nums.length。

注意：本题与主站 239 题相同
'''
from typing import List
from collections import deque   # use deque to fasten the pop(0) operation

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []

        max_s = deque()
        res=[]

        for i in range(k):
            while max_s and nums[i] > max_s[-1]:
                max_s.pop()
            max_s.append(nums[i])
                
        res = [max_s[0]]
        # print(max_s)

        n = len(nums)
        for i in range(k, n):
            in_val = nums[i]
            out_val = nums[i-k]
            if out_val == max_s[0]:
                max_s.popleft()
            while max_s and in_val > max_s[-1]:
                max_s.pop()
            max_s.append(in_val)
            res.append(max_s[0])
            # print(max_s, in_val,out_val)

        return res


a = Solution()
print(a.maxSlidingWindow([1, 3, 1, 2, 0, 5], 3))
# print(a.maxSlidingWindow([1, -1], 1))
