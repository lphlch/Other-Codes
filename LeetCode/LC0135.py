"""
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
"""


class Solution:
    def candy(self, ratings: List[int]) -> int:
        s_ratings = sorted(ratings)
        n = len(ratings)

        candies = [1] * n

        last_r = -1
        last_r_index = 0
        for r in s_ratings:
            if last_r != r:
                last_r = r
                last_r_index = 0

            curr_r_index = ratings.index(r, last_r_index)
            if curr_r_index == -1:
                continue

            if curr_r_index > 0 and ratings[curr_r_index] > ratings[curr_r_index - 1]:
                if candies[curr_r_index] <= candies[curr_r_index - 1]:
                    candies[curr_r_index] = candies[curr_r_index - 1] + 1
            if (
                curr_r_index < n - 1
                and ratings[curr_r_index] > ratings[curr_r_index + 1]
            ):
                if candies[curr_r_index] <= candies[curr_r_index + 1]:
                    candies[curr_r_index] = candies[curr_r_index + 1] + 1

            last_r_index = curr_r_index + 1
            print(curr_r_index, candies)

        print(candies)
        return sum(candies)
