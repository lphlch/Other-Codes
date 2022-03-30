'''
剑指 Offer 63. 股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

注意：本题与主站 121 题相同：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
'''


class Solution:
    def maxProfit(self, prices) -> int:
        length=len(prices)
        if length==0:
            return 0
        self.dp=[0]*length
        minPrice=prices[0]
        
        for i in range(0,length):
            minPrice=min(minPrice,prices[i])
            self.dp[i]=max(self.dp[i-1],prices[i]-minPrice)
            
        return self.dp[-1]
                