'''
剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部
请定义一个函数实现字符串左旋转操作的功能
比如，输入字符串"abcdefg"和数字2
该函数将返回左旋转两位得到的结果"cdefgab"。


'''

# Method 1:
# use slice (very easy)
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:]+s[:n]


# Method 2:
# extend the string and return the slice
# 
# extend the string by k
# from the end of string ,back-moving k steps
# each time copy the first part to the end of string
# return the address of the k position, where the new string starts
