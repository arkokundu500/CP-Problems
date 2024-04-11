//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        vector<long long> cnt(64, 0);
        long long ans = 0;
        for(int i = 0; i < 64; i++) for(int j = 0; j < n; j++) cnt[i] += (arr[j] >> i) & 1;
        for(int i = 0; i < 64; i++) ans += (1 << i) * (cnt[i]*(cnt[i]-1))/2;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends