//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    if (n == 1) {
        // If there's only one element, no difference to minimize
        return 0;
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Initialize the result as the initial difference
    int ans = arr[n-1] - arr[0];

    // The smallest and largest values after adding/subtracting k to arr[0] and arr[n-1]
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;

    // Traverse through the array and adjust the min/max
    for (int i = 0; i < n - 1; i++) {
        int min_val = min(smallest, arr[i+1] - k);  // The minimum possible value
        int max_val = max(largest, arr[i] + k);     // The maximum possible value

        // Ignore the case where min_val becomes negative
        if (min_val < 0) continue;

        // Update the result with the smallest possible difference
        ans = min(ans, max_val - min_val);
    }

    return ans;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends