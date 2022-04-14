'''
1049. Last Stone Weight II
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

1049. 最后一块石头的重量 II
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
'''

class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        sumNum=sum(stones)
        half=sumNum//2
        lenNum=len(stones)
        
        dp=[0]*(half+1)
        dp[0]=1
        for i in range(lenNum):
            for j in range(half+1,-1,-1):
                if (stones[i]+j)<=half and dp[j]==1:
                    dp[stones[i]+j]=1
                    
        for i in range(half,-1,-1):
            if dp[i]==1:
                return sumNum-2*i