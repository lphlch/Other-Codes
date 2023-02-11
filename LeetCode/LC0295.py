'''
295. 数据流的中位数
中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

例如 arr = [2,3,4] 的中位数是 3 。
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
实现 MedianFinder 类:

MedianFinder() 初始化 MedianFinder 对象。

void addNum(int num) 将数据流中的整数 num 添加到数据结构中。

double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。


295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
'''

from queue import PriorityQueue
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.low = PriorityQueue()
        self.high = PriorityQueue()


    def addNum(self, num: int) -> None:
        self.low.put(-num)
        self.high.put(-self.low.get())
        if self.low.qsize() < self.high.qsize():
            self.low.put(-self.high.get())


    def findMedian(self) -> float:
        if self.low.qsize() > self.high.qsize():
            return -self.low.queue[0]
        else:
            return (-self.low.queue[0] + self.high.queue[0]) / 2



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()