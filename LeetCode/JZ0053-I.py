'''
剑指 Offer 53 - I. 在排序数组中查找数字 I
统计一个数字在排序数组中出现的次数。

'''


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return nums.count(target)
