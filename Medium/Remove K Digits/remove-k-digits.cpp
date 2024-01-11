//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string str, int k) {
        
        int n=str.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            //to take all small digits at front of string 
            while(!st.empty() && st.top()>str[i] && k>0)
            {
                st.pop();
                k--;
            }
            
            st.push(str[i]);
        }
        
        if(st.empty())
          {
               return "0";
          }
          
          while(k--)
          {
              //condition if k>0 and we havent removed enough elements 
              st.pop();
          }
          
          
         //Now make a string that is present in reverse order in stack
         
         string rev="";
         while(!st.empty())
         {
             rev.push_back(st.top());
             st.pop();
         }
         
         
         // now reverse the string rev;
         
         reverse(rev.begin(),rev.end());
         
         //last condition was to avoid leading zeroes of our string,we would create string ans for final condition
         string ans="";
         int i=0;
         while(rev[i]=='0')
         {
             i++;
         }
         
         
         if(i==rev.length())
         {
             //after reversing stack,in our string we get values as 0 then return 0
             return "0";
         }
         
         if(rev[i]!='0')
         {
             for(int k=i;k<rev.length();k++)
             {
                 ans.push_back(rev[k]);
             }
             
             
             return ans;
         }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends