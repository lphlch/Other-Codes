'''
279. 完全平方数
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

'''
from queue import PriorityQueue


class Solution:
    def numSquares(self, n: int) -> int:
        pq=PriorityQueue()
        pq.put([0,n])
        while not pq.empty():
            curr=pq.get()
            # print("get:",curr)
            for i in range(1,int(curr[1]**0.5)+1):
                if curr[1]==i**2:
                    return curr[0]+1
                else:
                    pq.put([curr[0]+1,curr[1]-i**2])