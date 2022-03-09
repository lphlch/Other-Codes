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
