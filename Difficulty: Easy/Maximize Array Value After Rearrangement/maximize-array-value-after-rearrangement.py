#User function Template for python3

class Solution:
    def Maximize(self, a):
        MOD = 10**9 + 7
        a.sort()
        n = len(a)
        res = 0
        for i in range(n):
            res += a[i] * i
            res %= MOD
        return res    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        # k = int(input())
        ob = Solution()
        print(ob.Maximize(A))

# } Driver Code Ends