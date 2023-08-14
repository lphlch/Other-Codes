'''
228. 汇总区间

给定一个  无重复元素 的 有序 整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b

228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
'''


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:

        if not nums:
            return []
        if len(nums) == 1:
            return [str(nums[0])]

        last = nums[0]

        result_nums = []
        start = nums[0]

        for i in range(1, len(nums)):
            print(start, nums[i])
            if nums[i] == nums[i-1]+1:
                continue
            else:
                result_nums.append((start, nums[i-1]))
                start = nums[i]

        result = []
        # deal with result nums into repr
        for s, e in result_nums:
            if s == e:
                result.append(str(s))
            else:
                result.append(str(s)+"->"+str(e))

        # deal with the last element
        if len(result_nums) == 0 or result_nums[-1][-1] != nums[-1]:
            if start != nums[-1]:
                result.append(str(start)+"->"+str(nums[-1]))
            else:
                result.append(str(nums[-1]))

        return result
