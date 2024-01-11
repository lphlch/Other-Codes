class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        pointer = len(nums) - 1
        while pointer >= 0:
            if nums[pointer] == 0:
                nums.pop(pointer)
                nums.append(0)
            pointer -= 1
