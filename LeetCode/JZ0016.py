'''
剑指 Offer 16. 数值的整数次方
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

注意：本题与主站 50 题相同
'''

class Solution:
    def myPow(self, x: float, n: int) -> float:
        return x ** n