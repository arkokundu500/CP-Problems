//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
bool isBalanced(string& s) {
        // code here
        stack<char> st;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[') st.push(s[i]);
            else
            {
                if((st.empty()) and (s[i]==')' || s[i]==']' || s[i]=='}')) return false;
                
                char op_brkt=st.top();
                st.pop();
                //cout<<"op_brkt:"<<op_brkt<<" "<<"s[i]:"<<s[i]<<'\n';
                
                if(op_brkt=='(' and s[i]!=')') return false;
                else if(op_brkt=='[' and s[i]!=']') return false;
                else if(op_brkt=='{' and s[i]!='}') return false;
            }
        }
        
        if(!st.empty()) return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends