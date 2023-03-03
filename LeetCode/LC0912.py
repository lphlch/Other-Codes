'''
912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。

912. Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
'''

from typing import List
from random import randint

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        print(nums)
        if len(nums) <= 1:
            return nums
        index = randint(0, len(nums)-1)
        guard = nums[index]
        nums[0], nums[index] = nums[index], nums[0]
        i = 0
        j = len(nums)-1

        while True:
            while nums[j] >= guard and i < j:
                j -= 1
            while nums[i] <= guard and i < j:
                i += 1

            if i >= j:
                nums[0], nums[i] = nums[i], nums[0]
                return self.sortArray(nums[:i]) + [guard] + self.sortArray(nums[i+1:])

            else:
                nums[i], nums[j] = nums[j], nums[i]


a = Solution()
print(a.sortArray([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26]))
