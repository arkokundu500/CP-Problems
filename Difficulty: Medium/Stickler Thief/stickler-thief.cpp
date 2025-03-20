//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int fun(int i, vector<int> &a, int &n, vector<int> &dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int t = a[i] + fun(i+2, a, n, dp);
        int nt = fun(i+1, a, n, dp);
        
        return dp[i] = max(t, nt);    
        
    }
  
    int findMaxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n+1, -1);
        
        return fun(0, arr, n, dp);
        // return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends