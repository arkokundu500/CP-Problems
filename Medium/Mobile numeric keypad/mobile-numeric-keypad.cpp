//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
private: 
    long long f(int ind,int last,int n,vector<vector<int>>&adj,vector<vector<long long>>&dp){
        if( ind == n ) return 1;
        if( dp[ind][last] != -1 ) return dp[ind][last];
        long long  ans=0;
        for(auto it: adj[last]){
            ans=ans+f(ind+1,it,n,adj,dp);
        }
        return dp[ind][last]=ans;
    }
public:
    long long getCount(int n) {
        vector<vector<long long >> dp(n,vector<long long>(11,-1));
        vector<vector<int>>adj={{1,2,3,4,5,6,7,8,9,10},{1,2,4},{1,2,3,5},{2,3,6},{1,4,5,7},{2,4,5,6,8},{3,5,6,9},{4,7,8},{5,7,8,9,10},{6,8,9},{8,10}};
        return f(0,0,n,adj,dp);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends