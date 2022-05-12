'''
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

215. Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
'''

from random import randint


class Solution:
    def randomSelect(self, nums, l, r, k):
        p = randint(l, r)  # random select a number between l and r
        # swap the selected number with the last number
        nums[r], nums[p] = nums[p], nums[r]
        # the following is the same as quick select
        i = j = l
        while j < r:
            if nums[r] >= nums[j]:
                nums[i], nums[j] = nums[j], nums[i]  # swap
                i += 1

            j += 1

        nums[i], nums[r] = nums[r], nums[i]  # swap

        if i < r-k+1:
            return self.randomSelect(nums, i+1, r, k)
        elif i > r-k+1:
            return self.randomSelect(nums, l, i-1, k-r+i-1)
        else:
            return nums[i]

    def findKthLargest(self, nums: List[int], k: int) -> int:
        n=len(nums)
        return self.randomSelect(nums, 0, n-1, n-k+1)
