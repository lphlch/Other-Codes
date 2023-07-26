'''
238. 除自身以外数组的乘积

给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。


238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.


'''

# maintain two arrays, one for left product, one for right product (can be marged, see method 2)
# the answer is the product of left and right from the index


# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         left_product = [1]
#         for num in nums:
#             left_product.append(left_product[-1] * num)

#         right_product = [1]
#         for num in nums[::-1]:
#             right_product.append(right_product[-1] * num)

#         answer = []
#         for i in range(len(nums)):
#             answer.append(left_product[i] * right_product[len(nums) - i - 1])

#         return answer


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = [1]
        for num in nums:
            # use answer to store the left product directly
            answer.append(answer[-1] * num)

        right_product = 1
        for index, num in enumerate(nums[::-1]):
            answer[len(nums) - index - 1] = answer[len(nums) -
                                                   index - 1] * right_product
            right_product *= num    # update right product while updating answer

        return answer[:-1]
