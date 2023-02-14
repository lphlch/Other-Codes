'''
剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

注意：本题与主站 169 题相同
'''


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = {}
        length = len(nums)
        for num in nums:
            dic[num] = dic.get(num, 0)+1

        for key, value in dic.items():
            if value > length/2:
                return key
