'''
剑指 Offer 10- II. 青蛙跳台阶问题
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/
'''


class Solution:
    def numWays(self, n: int) -> int:
        if (n == 0):
            return 1
        count = [0]*(n+1)     # init count list
        count[0] = 1
        count[1] = 1
        for i in range(2, n+1):
            count[i] = (count[i-1]+count[i-2]) % 1000000007
        return count[n]

    # time out of limits
    '''
        if(n == 1):
            return 1
        if(n == 2):
            return 2
        sum = self.numWays(n-1)+self.numWays(n-2)
        return sum
    '''
