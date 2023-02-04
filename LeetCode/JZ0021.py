'''
剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

'''


class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        if not nums:
            return []

        head = 0
        tail = len(nums) - 1
        while head != tail:
            if nums[head] % 2 == 0:
                nums[head], nums[tail] = nums[tail], nums[head]
                tail -= 1
            else:
                head += 1

        return nums
