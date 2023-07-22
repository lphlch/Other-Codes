'''
1071. Greatest Common Divisor of Strings

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

'''


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        
        n = min(len(str1),len(str2))
        
        max_divisor = 0
        
        for i in range(1,n+1):
            if str1[:i] * (len(str1) // i) == str1 and str2[:i] * (len(str2) // i)  == str2:
                max_divisor= i
            print(str1[:i] * (len(str1) // i),str2[:i] * (len(str2) // i))
            
        #! in fact, the prefix of length of math.gcd(str1,str2) is the only possible solution (plus a '')
            
        return str1[:max_divisor]