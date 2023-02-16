'''
剑指 Offer 31. 栈的压入、弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

注意：本题与主站 946 题相同
'''

# for every next number, either in stack top or ready to push (maybe in more than one time to push)


class Solution:
    def validateStackSequences(self, pushed, popped) -> bool:
        s = []
        for num in popped:
            print(s)
            if s and s[-1] == num:
                s.pop()
            elif pushed and pushed[0] == num:
                pushed.pop(0)
            else:
                if not pushed:
                    return False
                while True:
                    if not pushed:
                        return False
                    elif pushed[0] == num:
                        pushed.pop(0)
                        break
                    s.append(pushed.pop(0))

        return True


a = Solution()
print(a.validateStackSequences([1, 2, 3, 4, 5], [4, 5, 3, 2, 1]))
