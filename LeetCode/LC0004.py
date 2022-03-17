'''
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
'''

class Solution:
    def f(self, nums1, nums2, k):
        if(len(nums1) < len(nums2)):
            nums1, nums2 = nums2, nums1
        if(len(nums2) == 0):
            return nums1[k-1]
        if(k == 1):
            return min(nums1[0], nums2[0])
        temp = min(k//2, len(nums2))
        if(nums1[temp-1] >= nums2[temp-1]):
            return self.f(nums1, nums2[temp:], k-temp)
        else:
            return self.f(nums1[temp:], nums2, k-temp)

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        k1 = (len(nums1) + len(nums2) + 1) // 2
        k2 = (len(nums1) + len(nums2) + 2) // 2

        return (self.f(nums1, nums2, k1) + self.f(nums1, nums2, k2)) / 2
