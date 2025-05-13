//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


// User function Template for C++

class Solution {
  public:
    
    // int nCr(int n, int r) {
    //     // code here
    //     vector<long long> calc(101);
    //     long long num=1;
    //     calc[0]=1;
    //     for(int i=1;i<=100;i++)
    //     {
    //         num=num*1ll*i;
    //         calc[i]=num;
    //     }
    //     long long d=calc[n-r]*1ll*calc[r];
    //     if (d == 0) return 0;
    //     long long nu=calc[n];
    //     return (int)nu/d;
    // }
    
    int nCr(int n, int r) {
    int dp[101][101];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}


};


//GFG POTD solution for 13 May



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends