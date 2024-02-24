//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    unordered_map<int,int> mp;
        int maxSum(int n)
        {
            int mx = n;
            return solve(n);
        }
        
        int solve(int n)
        {
            if(n<=4)
            {
                return n;
            }
            if(mp.find(n) != mp.end())
            {
                return mp[n];
            }
            return mp[n] = max(n, solve(n/2)+solve(n/3)+solve(n/4));
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends