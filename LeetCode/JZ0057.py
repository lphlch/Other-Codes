'''
剑指 Offer 57. 和为s的两个数字
输入一个递增排序的数组和一个数字s，在数组中查找两个数
使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        head = 0
        tail = len(nums) - 1
        while head < tail:
            if nums[head] + nums[tail] == target:
                return [nums[head], nums[tail]]
            elif nums[head] + nums[tail] > target:
                tail -= 1
            else:
                head += 1
                
        return []