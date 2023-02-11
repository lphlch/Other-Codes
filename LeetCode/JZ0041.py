'''
剑指 Offer 41. 数据流中的中位数
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

注意：本题与主站 295 题相同
'''
from queue import PriorityQueue
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s=[]


    def addNum(self, num: int) -> None:
        self.s.append(num)
        self.s.sort()


    def findMedian(self) -> float:
        n = len(self.s)
        if n % 2 == 0:
            return (self.s[n//2-1] + self.s[n//2]) / 2
        else:
            return self.s[n//2]



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()