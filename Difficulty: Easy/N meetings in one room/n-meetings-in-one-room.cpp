//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
   int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        list<pair<int,int>>lst;
        for(int i=0;i<n;i++)
        {
            lst.push_back(make_pair(end[i],start[i]));
        }
        lst.sort();
        int count = 0;
        int endtime = -1;
        for(auto itr=lst.begin();itr!=lst.end();itr++)
        {
            if(itr->second > endtime)
            {
                count++;
                endtime = itr->first;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends