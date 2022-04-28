'''
55. 跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
'''


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        
        farthest=0
        for i in range(n):
            if i>farthest:
                return False
            farthest=max(farthest,i+nums[i])
            
        return True if farthest>=n-1 else False