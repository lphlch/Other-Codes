'''
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

416. Partition Equal Subset Sum
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
'''
class Solution:
    def canPartition(self, nums) -> bool:
        sumNum=sum(nums)
        if sumNum%2!=0:
            return False
        
        lenNum=len(nums)
        half=sumNum//2
        dp=[0]*(half+1)
        dp[0]=1
        for i in range(lenNum):
            for j in range(half+1,-1,-1):
                if (nums[i]+j)<=half and dp[j]==1:
                    dp[nums[i]+j]=1
                    
                
                    
        return bool(dp[-1])