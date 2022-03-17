'''
53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。

53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
'''


class Solution:
    def findMaxCross(self,array,low,mid,high):
        lSum=-1000000
        sum=0
        maxL=0
        for i in range(mid,low-1,-1):
            sum+=array[i]
            if sum>lSum:
                lSum=sum
                maxL=i
        rSum=-1000000
        sum=0
        maxR=0
        for j in range(mid+1,high+1):
            sum+=array[j]
            if sum>rSum:
                rSum=sum
                maxR=j
        
        return (maxL,maxR,lSum+rSum)
                
    def findMax(self,array,low,high):
        if high==low:
            return (low,high,array[low])
        else:
            mid=(low+high)//2
            leftL,leftH,leftS=self.findMax(array,low,mid)
            rightL,rightH,rightS=self.findMax(array,mid+1,high)
            crossL,crossH,crossS=self.findMaxCross(array,low,mid,high)
            if leftS>=rightS and leftS>=crossS:
                return (leftL,leftH,leftS)
            elif rightS>=leftS and rightS>=crossS:
                return (rightL,rightH,rightS)
            else:
                return (crossL,crossH,crossS)
            
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        else:
            return self.findMax(nums,0,len(nums)-1)[2]