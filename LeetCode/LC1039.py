'''
1039. Minimum Score Triangulation of Polygon
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

1039. 多边形三角剖分的最低得分
你有一个凸的 n 边形，其每个顶点都有一个整数值。给定一个整数数组 values ，其中 values[i] 是第 i 个顶点的值（即 顺时针顺序 ）。

假设将多边形 剖分 为 n - 2 个三角形。对于每个三角形，该三角形的值是顶点标记的乘积，三角剖分的分数是进行三角剖分后所有 n - 2 个三角形的值之和。

返回 多边形进行三角剖分后可以得到的最低分 。
'''




class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        lenV = len(values)
        dp = [[0] * lenV for _ in range(0, lenV)]
        for length in range(3, lenV + 1) :
            for i in range(0, lenV - length + 1) :
                j = i + length - 1
                dp[i][j] = 999999999999999
                for k in range(i + 1, j) :
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j])

        return dp[0][lenV - 1]


