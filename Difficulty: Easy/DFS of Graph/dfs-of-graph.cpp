//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited){
        ans.push_back(i);
        visited[i] = true;
        
        for(auto z : adj[i]){
            if(!visited[z]){
                dfs(z, adj, ans, visited);
            }
            
        }
        return;
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        unordered_map<int, bool> visited;
        dfs(0, adj, ans, visited);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends