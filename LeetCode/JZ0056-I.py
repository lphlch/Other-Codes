'''
剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

'''

# a XOR a = 0
# use XOR to find which one appears once
# but the result is x XOR y
# so need to find a way to divide x and y
# as x and y are different, so there must be a bit that is different
# use this bit to divide x and y


class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        x_y = 0
        length = len(nums)
        for i in range(length):
            x_y ^= nums[i]

        m = 1
        while x_y & m == 0:
            m <<= 1

        x, y = 0, 0
        for num in nums:
            if num & m:
                x ^= num
            else:
                y ^= num
        return [x, y]
