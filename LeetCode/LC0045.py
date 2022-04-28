'''
45. 跳跃游戏 II
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。

45. Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
'''
class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        
        farthest=0
        endPos=0
        result=0
        for i in range(n-1):
            if farthest<i:
                break
            farthest=max(farthest,i+nums[i])
            if i==endPos:
                endPos=farthest
                result+=1
                
        return result