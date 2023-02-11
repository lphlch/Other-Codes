'''
面试题61. 扑克牌中的顺子
从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

'''


class Solution:
    def isStraight(self, nums) -> bool:
        def trans(x):
            if x == 'A':
                return 1
            elif x == 'J':
                return 11
            elif x == 'Q':
                return 12
            elif x == 'K':
                return 13
            else:
                return int(x)

        s = sorted(nums, key=trans)
        nums.sort(key=trans)
        print(s)

        sum = 0
        for i in range(4):
            if s[i] == 0:
                sum += 1
            elif s[i] == s[i+1]:
                return False
            else:
                sum -= s[i+1] - s[i] - 1

        if sum >= 0:
            return True
        else:
            return False


a = Solution()
print(a.isStraight([0, 0, 1, 2, 5]))
