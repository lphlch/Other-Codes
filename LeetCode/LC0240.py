'''
240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

240. Search a 2D Matrix II
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
'''

# quick? how to use range to locate the position?
# need to ensure only one direction each compare result
# start from the top right corner
# if target < matrix[i][j], move left
# if target > matrix[i][j], move down

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
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

# python solution
# class Solution:
#     def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
#         return target in chain(*matrix) # * to unpack the matrix