'''
剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下
请实现它的两个函数 appendTail 和 deleteHead 
分别完成在队列尾部插入整数和在队列头部删除整数的功能
(若队列中没有元素，deleteHead 操作返回 -1 )

'''


class CQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def appendTail(self, value: int) -> None:
        self.stack1.append(value)

    def deleteHead(self) -> int:
        if self.stack1 == []:
            return -1

        for item in self.stack1:
            self.stack2.append(item)

        pop_out = self.stack2[0]
        self.stack1.clear()

        for item in self.stack2[1:]:
            self.stack1.append(item)

        self.stack2.clear()

        return pop_out


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
