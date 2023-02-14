'''
剑指 Offer 66. 构建乘积数组
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。

不能使用除法。
'''

# Easy to use dp to solve b[i] = a[0]*a[1]*...*a[i-1]
# In such problem we can get b[i] = b[i-1]*a[i-1]
# For this problem, use two dp to solve it
# one is from left to right, another is from right to left


class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        low_dp = [1]
        length_a = len(a)
        for i in range(1, length_a):
            low_dp.append(low_dp[-1]*a[i-1])

        high_dp = [1]*length_a
        for i in range(len(a)-2, -1, -1):
            high_dp[i] = high_dp[i+1]*a[i+1]

        b = []
        for i in range(length_a):
            b.append(low_dp[i]*high_dp[i])

        return b
