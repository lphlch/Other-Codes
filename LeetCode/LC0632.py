'''
632. 最小区间
你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。

我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

632. Smallest Range Covering Elements from K Lists
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
'''
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:

        small = []
        big = []
        length = len(nums)
        
        left = -inf
        right = inf
        
        curNumPointer = [0] * length

        for i in range(length):
            heappush(small, (nums[i][0], i, 0))
            heappush(big, (-nums[i][0], i, 0))


        while True:
            minNum, i, j = heappop(small)
            maxNum, m, n = big[0]

            while big and n < curNumPointer[m]:
                maxNum, m, n = heappop(big)

            if -maxNum - minNum < right - left:
                left = minNum
                right = -maxNum

            if j + 1 == len(nums[i]):
                break
            heappush(small, (nums[i][j + 1], i, j + 1))
            heappush(big, (-nums[i][j + 1], i, j + 1))
            curNumPointer[i] += 1
        return [left, right]