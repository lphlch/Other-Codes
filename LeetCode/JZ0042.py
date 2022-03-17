'''
剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
'''
class Solution:
    def fingMaxCrossingSubarray(self,array,low,mid,high):
        leftSum=-1000000
        sum=0
        maxLeft=0
        for i in range(mid,low-1,-1):
            sum+=array[i]
            if sum>leftSum:
                leftSum=sum
                maxLeft=i
        rightSum=-1000000
        sum=0
        maxRight=0
        for j in range(mid+1,high+1):
            sum+=array[j]
            if sum>rightSum:
                rightSum=sum
                maxRight=j
        
        return (maxLeft,maxRight,leftSum+rightSum)
                
    def findMaxSubarray(self,array,low,high):
        if high==low:
            return (low,high,array[low])
        else:
            mid=(low+high)//2
            leftLow,leftHigh,leftSum=self.findMaxSubarray(array,low,mid)
            rightLow,rightHigh,rightSum=self.findMaxSubarray(array,mid+1,high)
            crossLow,crossHigh,crossSum=self.findMaxCrossingSubarray(array,low,mid,high)
            if leftSum>=rightSum and leftSum>=crossSum:
                return (leftLow,leftHigh,leftSum)
            elif rightSum>=leftSum and rightSum>=crossSum:
                return (rightLow,rightHigh,rightSum)
            else:
                return (crossLow,crossHigh,crossSum)
            
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        else:
            return self.findMaxSubarray(nums,0,len(nums)-1)[2]
    
            
array=[-2,1,-3,4,-1,2,1,-5,4]
print(findMaxSubarray(array,0,len(array)-1))