'''
9. Palindrome Number 回文数
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
例如， 121 是回文，而 123 不是。
'''

class Solution:
    def isPalindrome(self, x: int) -> bool:
        xs=str(x)
        xss=''.join(reversed(xs))
        if(xs==xss):
            return True
        return False
    
s=Solution()
s.isPalindrome(121)