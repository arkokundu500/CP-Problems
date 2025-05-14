//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



map<int, string> dp;

class Solution {
  public:
    string countAndSay(int n) 
    {
        if(n==1) return "1";
        if(dp.count(n)) return dp[n];
        
        string s = countAndSay(n-1), ans;
        
        int cnt = 0;
        char c = s[0];
        s += '#';
        
        for(char &ch: s)
        {
            if(ch==c) cnt++;
            else 
            {
                ans += ('0'+cnt);
                ans += c;
                cnt = 1;
                c = ch;
            }
        }
        
        return dp[n] = ans;
    }
};


//GFG POTD solution for 14 May



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends