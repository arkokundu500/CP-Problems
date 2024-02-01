//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
         unordered_map<char, int> mp;
        int t = 97;

        for (int i = 0; i < 26; i++) {
            char temp = 'a' + (t - 'a');
            mp[temp]++;
            t++;
        }

        for (auto i : s) {
            if (i >= 'a' && i <= 'z')
                mp[i]++;
            if (i >= 'A' && i <= 'Z') {
                char temp = tolower(i);
                mp[temp]++;
            }
        }

        for (auto i : mp) {
            if (i.second <= 1)
                return 0;
        }
        return 1;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends