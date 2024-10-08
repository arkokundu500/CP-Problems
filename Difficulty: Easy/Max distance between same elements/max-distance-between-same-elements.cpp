//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,int>mpp;
        int max_diff=0;
        for(int i=0;i<arr.size();i++){
            
            
            if(mpp.find(arr[i]) != mpp.end()){
                max_diff = max(max_diff,i-mpp[arr[i]]);
            }
            else
            mpp[arr[i]] = i;    
        }
        return max_diff;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends