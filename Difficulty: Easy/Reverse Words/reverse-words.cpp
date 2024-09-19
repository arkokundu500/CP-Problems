//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string reverseWords(string str) {
        string ans = "";
        
        for(int i=str.size()-1;i>=0;){
            string temp = "";
            while(i >= 0 && str[i] != '.'){
                temp += str[i];
                i--;
            }
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans += str[i--];
        }
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends