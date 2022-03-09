class Solution:
    def partition(self,arr,p,r,k):
        #print('partition',p,r,k)
        i=p+1
        j=r
        x=k
        while True:
            while arr[i]<x and i<r:
                #print('i',i)
                i+=1
            while arr[j]>=x and j>p:
                #print('j',j)
                j-=1
            if i>=j:
                break
            arr[i],arr[j]=arr[j],arr[i]
        pos=arr.index(x)
        arr[pos]=arr[j]
        arr[j]=x
        return j
    
    
    def select(self,arr,p,r,k):
        #print('selecting',p,r,k)
        if(r-p<75):
            arr[p:r+1]=sorted(arr[p:r+1])
            return arr[p+k-1]
        
        for i in range(0,int((r-p-4)/5+1)):
            arr[p+5*i:p+5*i+4+1]=sorted(arr[p+5*i:p+5*i+4+1])    # sort 5 elements, for get the median
            arr[p+i],arr[p+5*i+2]=arr[p+5*i+2],arr[p+i]   # swap the median to the first position, for better getting the median of medians
            x=self.select(arr,p,int(p+(r-p-4)/5),int((r-p-4)/10))
            i=self.partition(arr,p,r,x)    # partition the array
            j=i-p+1
            if(k<=j):
                return self.select(arr,p,i,k)
            else:
                return self.select(arr,i+1,r,k-j)
            
    def getLeastNumbers(self, arr, k: int):
        kthNum=self.select(arr,0,len(arr)-1,k)
        nums=[num for num in arr if num<=kthNum]
        nums.sort()
        return nums[:k]
    
    
s=Solution()
arr=[0,0,2,3,3,5,6,0,3,4,4,4,3,0,9,14,4,17,6,4,10,18,21,13,8,4,12,6,19,11,8,12,14,7,16,34,19,18,15,14,22,41,32,23,27,37,2,30,14,12,23,41,39,2,21,32,22,1,12,25,6,46,7,61,13,64,54,56,29,41,51,2,9,65,17,28,34,41,1,62,23,14,60,14,22,17,67,86,81,45,78,9,27,17,30,54,35,42,72,94]
k=21
print(s.getLeastNumbers(arr,k))