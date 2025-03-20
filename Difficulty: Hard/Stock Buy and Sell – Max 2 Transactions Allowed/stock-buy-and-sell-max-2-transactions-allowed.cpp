//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));
        
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int k=0; k<=2; k++)
                {
                    int profit = 0;
                    if(buy)
                    {
                        int include = -prices[index] + next[0][k];
                        int exclude = next[1][k];
                        profit = max(include,exclude);
                    }
                    else
                    {
                        if( k-1 >= 0)
                        {
                            int include = prices[index] + next[1][k-1];
                            int exclude = next[0][k];
                            profit = max(include,exclude);
                        }
                    }
                    curr[buy][k] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int> &prices) {
        
        return solveTab(prices);
      
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends