//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod = 1e9 + 7;
    int f(int x, int y, vector<vector<int>> &dp){
        if(x<0 || y<0){
            return 0;
        }
        
        if(x==0 && y==0){
            return 1;
        }
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        //keepx and decrease y
        int keepx=f(x,y-1,dp);
        //keepy and decrease x
        int keepy=f(x-1,y,dp);
        
        return dp[x][y]=(keepx+keepy)% mod;
    }
    
    int ways(int x, int y)
    {
        vector<vector<int>> dp(x+1, vector<int>(y+1,-1));
        return f(x,y,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends