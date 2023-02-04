'''
剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：
0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”
一个数字可能有多个翻译
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

'''


class Solution:
    def translateNum(self, num: int) -> int:
        dp = []
        for i, c in enumerate(str(num)):
            print(i, c)
            print(dp)
            if i == 0:
                dp.append(1)
            elif i == 1:
                dp.append(2 if int(c)+int(str(num)[i-1])*10 < 26 else 1)
            else:
                dp.append(dp[-1]+dp[-2] if (int(c) +
                          int(str(num)[i-1])*10 < 26) and str(num)[i-1] != '0' else dp[-1])

        return dp[-1]
