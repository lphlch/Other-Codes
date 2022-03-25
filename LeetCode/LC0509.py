'''
509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

509. 斐波那契数
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。
'''

class Solution:
    def fib(self, n: int) -> int:
        if n<2:
            return n
        memo=[0,1,-1]
        i=0
        while i<n:
            i+=1
            memo[2]=memo[0]+memo[1]
            memo[0]=memo[1]
            memo[1]=memo[2]
        
        return memo[0]