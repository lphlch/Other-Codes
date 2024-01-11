class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)

        res = 0
        l = 0
        r = n - 1

        # 2 pointers
        # only move the shorter one as the area is determined by it

        while l < r:
            res = max(res, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return res
