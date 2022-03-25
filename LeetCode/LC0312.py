'''
312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

312. 戳气球
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。
'''

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1]+nums+[1]
        lenNum = len(nums)
        money = [[0]*lenNum for _ in range(lenNum)]

        for i in range(2, lenNum):
            for j in range(0, lenNum-i):
                curMax = 0
                for k in range(j+1, j+i):
                    l = money[j][k]
                    r = money[k][j+i]
                    tmp = l + nums[j]*nums[k]*nums[j+i] + r
                    if tmp > curMax:
                        curMax = tmp
                money[j][j+i] = curMax

        return money[0][lenNum-1]
