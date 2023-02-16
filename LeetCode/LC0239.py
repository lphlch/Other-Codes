'''
239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

'''


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []

        max_s = deque()
        res = []

        for i in range(k):
            while max_s and nums[i] > max_s[-1]:
                max_s.pop()
            max_s.append(nums[i])

        res = [max_s[0]]
        # print(max_s)

        n = len(nums)
        for i in range(k, n):
            in_val = nums[i]
            out_val = nums[i-k]
            if out_val == max_s[0]:
                max_s.popleft()
            while max_s and in_val > max_s[-1]:
                max_s.pop()
            max_s.append(in_val)
            res.append(max_s[0])
            # print(max_s, in_val,out_val)

        return res
