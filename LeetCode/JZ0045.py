'''
面试题45. 把数组排成最小的数
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
'''

# sort the numbers in the array
# if 'ab' > 'ba', then a > b
# use functools.cmp_to_key to convert the cmp function to custom function with 2 parameters


class Solution:
    def minNumber(self, nums: List[int]) -> str:
        nums.sort(key=functools.cmp_to_key(
            lambda x, y: 1 if str(x) + str(y) > str(y) + str(x) else -1))
        return ''.join([str(i) for i in nums])
