'''
剑指 Offer 49. 丑数
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

说明:  
1 是丑数。
n 不超过1690。

注意：本题与主站 264 题相同
'''


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        uglys = [1]
        a = b = c = 0
        for i in range(1, n):
            use_a = uglys[a]*2
            use_b = uglys[b]*3
            use_c = uglys[c]*5
            min_value = min(use_a, use_b, use_c)
            if min_value == use_a:
                a += 1
            if min_value == use_b:
                b += 1
            if min_value == use_c:
                c += 1
            uglys.append(min_value)
        return uglys[-1]
