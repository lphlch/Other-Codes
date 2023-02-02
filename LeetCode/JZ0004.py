'''
剑指 Offer 04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右 非递减 的顺序排序
每一列都按照从上到下 非递减 的顺序排序
请完成一个高效的函数，输入这样的一个二维数组和一个整数
判断数组中是否含有该整数。

注意：本题与主站 240 题相同
'''

# quick? how to use range to locate the position?
# need to ensure only one direction each compare result
# start from the top right corner
# if target < matrix[i][j], move left
# if target > matrix[i][j], move down


class Solution:
    def findNumberIn2DArray(self, matrix, target: int) -> bool:
        i = 0
        j = len(matrix[0])-1 if len(matrix) > 0 else -1

        while i < len(matrix) and j >= 0:
            cur = matrix[i][j]
            # print(i, j)
            # print(cur)
            if target == cur:
                return True

            if target < cur:
                j -= 1
            else:
                i += 1

        return False


a = Solution()
print(a.findNumberIn2DArray([], 0))
