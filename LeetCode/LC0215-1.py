'''
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

215. Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
'''



from heapq import heapify, heappop, heappush


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        l=[num for num in nums[:k]]
        
        heapify(l)
        for i in range(k,len(nums)):
            if nums[i] > (l[0]):
                # replace the biggest element in the heap with the current element
                heappop(l)
                heappush(l,nums[i])

        return l[0]
    
    
    
