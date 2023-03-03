'''
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
'''


from unittest import TestCase as tc


class Solution:
    def trap(self, height) -> int:
        left = 0
        right = 0
        curr = 0
        right_value = 0

        sum = 0
        # 向左求最高
        # 开始不用管，后来直接换位即可
        n = len(height)
        while curr < n:
            # 向右求最高
            if right <= curr:
                right_value = height[curr]
                for i in range(curr+1, n):
                    if height[i] >= right_value:
                        right = i
                        right_value = height[i]

                if right == curr:
                    print("right == curr", curr, height[curr])
                    if height[left] <= height[curr]:
                        left = curr
                    right += 1
                    curr += 1
                    continue
            print(left, height[left], curr, height[curr], right, height[right])

            # 求当前列水含量
            if height[left] <= height[curr]:
                left = curr
            elif height[curr] >= height[right]:
                pass
            elif height[left] > height[curr] and height[curr] < height[right]:
                sum += min(height[left], height[right]) - height[curr]
            curr += 1
        return sum


a = Solution()

tc().assertEqual(a.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6)
tc().assertEqual(a.trap([4, 2, 0, 3, 2, 5]), 9)
tc().assertEqual(a.trap([4, 2, 3]), 1)
