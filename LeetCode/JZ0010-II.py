class Solution:
    def numWays(self, n: int) -> int:
        if(n == 0):
            return 1
        count=[0]*(n+1)     # init count list
        count[0]=1
        count[1]=1
        for i in range(2,n+1):
            count[i]=(count[i-1]+count[i-2]) % 1000000007
        return count[n]
    
    # time out of limits
    '''
        if(n == 1):
            return 1
        if(n == 2):
            return 2
        sum = self.numWays(n-1)+self.numWays(n-2)
        return sum
    '''