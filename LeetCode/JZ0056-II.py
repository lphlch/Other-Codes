'''
剑指 Offer 56 - II. 数组中数字出现的次数 II
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

'''

# use dfa to find a bit that occurs only times that are not a multiple of 3
# two dimensional array
# 0    0    0    0  high
# 1    0    1    0  low
# 1 -> 0 -> 1 -> 0  original


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        high, low = 0, 0
        for num in nums:
            low = ~high & (low ^ num)
            high = ~low & (high ^ num)
        return low
