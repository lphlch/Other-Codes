'''
剑指 Offer 29. 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

注意：本题与主站 54 题相同
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

# a=Solution()
# print(a.spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))

# # 1 2 3
# # 4 5 6
# # 7 8 9
