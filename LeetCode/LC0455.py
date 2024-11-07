"""
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
"""


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        happy_children = 0
        index_point = 0
        for c in g:
            if index_point >= len(s):
                break

            while True:
                if c <= s[index_point]:
                    happy_children += 1
                    index_point += 1
                    break
                else:
                    index_point += 1
                    if index_point >= len(s):
                        break
        return happy_children
