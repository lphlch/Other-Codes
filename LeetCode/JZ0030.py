'''
剑指 Offer 30. 包含min函数的栈

定义栈的数据结构
请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中
调用 min、push 及 pop 的时间复杂度都是 O(1)。

本题与主站 155 题相同
'''

# record the current min value when push


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []

    def push(self, x: int) -> None:
        if self.stack == []:
            self.stack.append((x, x))
        else:
            if x < self.stack[-1][1]:
                self.stack.append((x, x))
            else:
                self.stack.append((x, self.stack[-1][1]))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def min(self) -> int:
        return self.stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
