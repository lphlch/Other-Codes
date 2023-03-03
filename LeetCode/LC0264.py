'''
264. 丑数 II
给你一个整数 n ，请你找出并返回第 n 个 丑数 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。

264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.
'''

from heapq import heappush, heappop


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        uglys = [1]
        c = 0
        s = set()
        while c < n:
            # print(uglys)
            out = heappop(uglys)
            c += 1
            if c == n:
                return out

            if out*2 not in s:
                s.add(out*2)
                heappush(uglys, out*2)
            if out*3 not in s:
                s.add(out*3)
                heappush(uglys, out*3)
            if out*5 not in s:
                s.add(out*5)
                heappush(uglys, out*5)
