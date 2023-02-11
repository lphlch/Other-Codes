'''
面试题13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？
'''


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def check(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or is_visited[i][j] or (i // 10 + i % 10 + j // 10 + j % 10) > k:
                return False
            return True

        def print_is_visited():
            for i in range(m):
                for j in range(n):
                    if is_visited[i][j]:
                        print('1', end=' ')
                    else:
                        print('0', end=' ')
                print()

        is_visited = [[False] * n for _ in range(m)]

        s = [(0, 0)]
        while s:
            i, j = s.pop()
            is_visited[i][j] = True
            if check(i+1, j):
                s.append((i+1, j))
            if check(i-1, j):
                s.append((i-1, j))
            if check(i, j+1):
                s.append((i, j+1))
            if check(i, j-1):
                s.append((i, j-1))

        # print_is_visited()

        return sum(sum(i) for i in is_visited)
