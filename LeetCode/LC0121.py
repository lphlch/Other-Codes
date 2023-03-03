'''
121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
'''


class Solution:
    def maxProfit(self, prices) -> int:
        length = len(prices)
        self.dp = [0]*length
        minPrice = prices[0]

        for i in range(0, length):
            minPrice = min(minPrice, prices[i])
            self.dp[i] = max(self.dp[i-1], prices[i]-minPrice)

        return self.dp[-1]
