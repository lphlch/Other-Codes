'''
剑指 Offer 47. 礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物
每个礼物都有一定的价值（价值大于 0）
你可以从棋盘的左上角开始拿格子里的礼物
并每次向右或者向下移动一格、直到到达棋盘的右下角
给定一个棋盘及其上面的礼物的价值
请计算你最多能拿到多少价值的礼物？

'''


class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        line = len(grid)
        col = len(grid[0])

        value = [[0 for i in range(col)] for j in range(line)]
        for i in range(line):
            for j in range(col):
                if i == 0 and j == 0:
                    value[i][j] = grid[i][j]
                elif i == 0:
                    value[i][j] = value[i][j-1] + grid[i][j]
                elif j == 0:
                    value[i][j] = value[i-1][j] + grid[i][j]
                else:
                    value[i][j] = max(value[i-1][j], value[i]
                                      [j-1]) + grid[i][j]

        return value[line-1][col-1]
