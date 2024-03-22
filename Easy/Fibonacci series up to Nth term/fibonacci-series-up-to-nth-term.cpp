//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 vector<int> Series(int n) {
        int mod=1000000007;
        vector<int> ans;
        int first=0;
        int sec=1;
            ans.push_back(first);
            ans.push_back(sec);
        while(n-2>=0){
            int sum=(first+sec)%mod;
            ans.push_back(sum);
            first=sec;
            sec=sum;
            n--;
        }
        return ans;
        
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends