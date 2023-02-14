'''
343. 整数拆分
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。

343. Integer Break
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

'''


class Solution:
    def integerBreak(self, n: int) -> int:
        res = []
        for m in range(2, n+1):
            every = round(n/m)
            diff = n - every*(m-1)
            res.append(every**(m-1)*diff)
            # print(every,diff)

        return max(res)
