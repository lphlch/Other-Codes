'''
70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        count=[0]*(n+1)     # init count list
        count[0]=1
        count[1]=1
        for i in range(2,n+1):
            count[i]=count[i-1]+count[i-2]
        return count[n]
        
        
        
    # time out of limits
    '''
        if(n == 1):
            return 1
        if(n == 2):
            return 2
        sum = self.climbStairs(n-1)+self.climbStairs(n-2)
        return sum
    '''

s = Solution()
n = int(input())
all = s.climbStairs(n)
print(all)
