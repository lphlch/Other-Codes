'''
96. 不同的二叉搜索树
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

96. Unique Binary Search Trees
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
'''

class Solution:
    dp=[]
    def numTrees(self, n: int) -> int:
        # init dp
        if self.dp==[]:
            self.dp=[0]*(n+1)
        
        # base case
        if n==1 or n==0:
            self.dp[1]=1
            return 1
        if n==2:
            self.dp[2]=2
            return 2
        
        # dynamic programming
        if self.dp[n]!=0:
            return self.dp[n]
        
        # recursive
        sum=0
        for i in range(1,n+1):
            sum+=self.numTrees(i-1)*self.numTrees(n-i)
        self.dp[n]=sum
        
        return sum