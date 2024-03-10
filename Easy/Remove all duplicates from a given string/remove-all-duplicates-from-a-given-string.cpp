//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
 string removeDuplicates(string str) {
        const int CHAR=256;
        
        vector<char> vis(CHAR,-1);
        string newstring="";
        
        for(int i=0;i<str.length();i++)
        {
            
            char s=str[i];
            if(vis[s]==-1){ 
                vis[s]=1;
                newstring+=s;
            }else continue;
           
        }
        
        return newstring;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends