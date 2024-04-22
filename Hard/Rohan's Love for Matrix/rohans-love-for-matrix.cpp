//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for 
class Solution {
    const int MOD = 1e9 + 7;
    
  public:
    int firstElement(int n) {
        vector<vector<long long>> origMat = {{1, 1},
                                            {1, 0}};
        vector<vector<long long>> curMat = {{1, 1},
                                            {1, 0}};
        
        for(int i = 1; i < n; i++) {
            long long a = curMat[0][0];
            long long b = curMat[0][1];
            long long c = curMat[1][0];
            long long d = curMat[1][1];
            
            curMat[0][0] = (a * origMat[0][0]) % MOD + (b * origMat[1][0]) % MOD;
            curMat[0][1] = (a * origMat[0][1]) % MOD + (b * origMat[1][1]) % MOD;
            curMat[1][0] = (c * origMat[0][0]) % MOD + (d * origMat[1][0]) % MOD;
            curMat[1][1] = (c * origMat[0][1]) % MOD + (d * origMat[1][1]) % MOD;
        }
        
        return curMat[1][0] % MOD;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends