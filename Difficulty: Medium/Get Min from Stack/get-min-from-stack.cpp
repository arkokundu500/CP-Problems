//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  vector<pair<int,int>> stk;
  public:
    Solution() {
    }

    void push(int x) {
        if(stk.size()==0) {
            stk.push_back(make_pair(x,x));
        }else{
            stk.push_back(make_pair(x,min(x,stk.back().second)));
        }
    }


    void pop() {
        if(stk.size()==0) return;
        stk.pop_back();
    }


    int peek() {
        if(stk.size()==0) return -1;
        return stk.back().first;
    }

    int getMin() {
        if(stk.size()==0) return -1;
        return stk.back().second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends