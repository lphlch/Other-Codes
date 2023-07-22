'''
剑指 Offer 14- I. 剪绳子
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

注意：本题与主站 343 题相同
'''

# 最优解就是尽可能地分解出长度为 3 的小段
# 小于等于 4 不再分解


class Solution:
    def cuttingRope(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        res = 1
        while n > 4:
            n -= 3
            res = int(res*3)

        res = int(res*n)
        return int(res % 1000000007) #! can not use 1e9+7 as .0 will be appended


print(1e9+7)
print(1000000007)
