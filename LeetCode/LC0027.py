'''
27. 移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

27. Remove Element


Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

'''

# two pointer like moving odd and even number

class Solution:
    def removeElement(self, nums, val: int) -> int:
        if not nums:    #! take care of []
            return 0
        
        left = 0
        right = len(nums) - 1
        k = 0
        
        while True:
            # find the val to remove
            while left < right and nums[left] != val:
                if nums[left] != val:
                    k += 1
                left += 1
            # find a element to replace
            while left < right and nums[right] == val:
                if nums[right] != val:
                    k += 1
                right -= 1

            if left >= right:
                if nums[left] != val:
                    k += 1
                break
            nums[left], nums[right] = nums[right], nums[left]

        return k


s = Solution()
print(s.removeElement([3, 2, 2, 3], 3))
