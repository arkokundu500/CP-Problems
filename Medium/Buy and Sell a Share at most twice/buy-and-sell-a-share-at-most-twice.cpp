//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxProfit(std::vector<int>& price) {
        int n = price.size();
        if (n <= 1) return 0;
        
        // Initialize profit arrays for two transactions
        std::vector<int> profit1(n, 0); // stores maximum profit with one transaction
        std::vector<int> profit2(n, 0); // stores maximum profit with two transactions
        
        // Calculate maximum profit with one transaction
        int minPrice = price[0];
        for (int i = 1; i < n; ++i) {
            minPrice = std::min(minPrice, price[i]);
            profit1[i] = std::max(profit1[i - 1], price[i] - minPrice);
        }
        
        // Calculate maximum profit with two transactions
        int maxPrice = price[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = std::max(maxPrice, price[i]);
            profit2[i] = std::max(profit2[i + 1], maxPrice - price[i]);
        }
        
        // Find maximum total profit by combining one transaction from left and one from right
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = std::max(maxProfit, profit1[i] + profit2[i]);
        }
        
        return maxProfit;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends