#User function Template for python3
from collections import Counter
class Solution:
	def countPairsWithDiffK(self,arr, k):
    	# code here
    	d=Counter(arr)
        ctr=0
        for i in arr:
            if i-k in d:
                ctr+=d[i-k]
    	return ctr



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.countPairsWithDiffK(arr, k)
        print(ans)
        print("~")
        tc -= 1

# } Driver Code Ends