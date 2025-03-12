#Back-end complete function Template for Python 3

class Solution:
    def minCostClimbingStairs(self, cost):
        x_0 = x_1 = 0
        for c in cost:
            x_0, x_1 = x_1, min(x_0, x_1) + c
        return min(x_0, x_1)  


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    arr = list(map(int, input().split()))  # Input array
    obj = Solution()
    res = obj.minCostClimbingStairs(arr)
    print(res)
    print("~")

# } Driver Code Ends