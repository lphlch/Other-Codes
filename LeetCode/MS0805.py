'''
面试题 08.05. 递归乘法
递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。

面试题 08.05. Recursive Mulitply LCCI
Write a recursive function to multiply two positive integers without using the * operator.
You can use addition, subtraction, and bit shifting,
but you should minimize the number of those operations.
'''

class Solution:
    def multiply(self, A: int, B: int) -> int:
        if A==1:
            return B
        
        if A%2==0:
            return self.multiply(A>>1,B)<<1
        else:
            return B+(self.multiply(A>>1,B)<<1)