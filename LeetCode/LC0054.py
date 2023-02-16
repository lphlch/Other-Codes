'''
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

'''


class Solution:
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        line = len(matrix)
        col = len(matrix[0])

        left, right, top, bottom = 0, col-1, 0, line-1
        res = []
        while left <= right and top <= bottom:
            # right
            for i in range(left, right+1):
                # print(top, i)
                res.append(matrix[top][i])
            top += 1

            if left > right or top > bottom:
                break
            # down
            for i in range(top, bottom+1):
                # print(i, right)
                res.append(matrix[i][right])
            right -= 1

            if left > right or top > bottom:
                break
            # left
            for i in range(right, left-1, -1):
                # print(bottom, i)
                res.append(matrix[bottom][i])
            bottom -= 1

            if left > right or top > bottom:
                break
            # up
            for i in range(bottom, top-1, -1):
                # print(i, left)
                res.append(matrix[i][left])
            left += 1

        return res
