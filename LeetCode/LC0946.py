'''
946. 验证栈序列
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，
只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，
返回 true；否则，返回 false 。

946. Validate Stack Sequences
Given two integer arrays pushed and popped each with distinct values, 
return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
'''


class Solution:
    def validateStackSequences(self, pushed, popped) -> bool:
        s = []
        for num in popped:
            # print(s)
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
