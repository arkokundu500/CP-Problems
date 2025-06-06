//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set <char> s;
        for(char c : str){
            s.insert(c);
        }
        unordered_map<char, int> mpp;
        int i=0, j=0, len = str.length();
        while(j<str.size()){
            mpp[str[j]]++;
            if(mpp.size() == s.size()){
                while(mpp[str[i]] > 1){
                    mpp[str[i]]--;
                    i++;
                }
                len = min(len, j-i+1);
            }
            j++;
        }
        return len;
    }
};


//GFG POTD solution for 04 May



//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends