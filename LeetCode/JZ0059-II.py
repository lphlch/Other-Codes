'''
面试题59 - II. 队列的最大值
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1


'''

# humdrum queue to maintain max value

from queue import Queue
from collections import deque


class MaxQueue:

    def __init__(self):
        self.q = Queue()
        self.dq = deque()

    def max_value(self) -> int:
        # print('max,q=', self.q, 'dq=', self.dq)
        return self.dq[0] if self.dq else -1

    def push_back(self, value: int) -> None:
        self.q.put(value)
        while (self.dq and self.dq[-1] < value):
            self.dq.pop()
        self.dq.append(value)
        # print('push', value, 'q=', self.q, 'dq=', self.dq)

    def pop_front(self) -> int:
        if self.q.empty():
            return -1
        out = self.q.get()
        if out == self.dq[0]:
            self.dq.popleft()
        # print('pop', out, 'q=', self.q, 'dq=', self.dq)
        return out


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
