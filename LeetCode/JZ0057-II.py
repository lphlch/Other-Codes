'''
剑指 Offer 57 - II. 和为s的连续正数序列
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

'''


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        arr = [1, 2]
        sum = 3
        for i in range(3, target):
            # print(arr,sum)
            if sum == target:
                res.append(arr.copy())
                # print(res)

            arr.append(i)
            sum += i
            while sum > target:
                sum -= arr[0]
                arr.pop(0)

        return res
