//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int lcs(int i,int j,string &s,string &s1,vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s1[j])
            return dp[i][j]=1+lcs(i-1,j-1,s,s1,dp);
        return dp[i][j] = max(lcs(i-1,j,s,s1,dp), lcs(i,j-1,s,s1,dp));
    }
  
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        return lcs(n-1,n-1,s,s1,dp);
        
    }
};

//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends