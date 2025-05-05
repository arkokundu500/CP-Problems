//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size(), low = 0, high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // 0 case  // n-1 case
            if(high == low+1) {
                if(arr[low] == target) return low;
                else if(arr[high] == target) return high;
                break;
            }
            // middle case
            else {
                int a = arr[mid-1];
                int b = arr[mid];
                int c = arr[mid+1];
                
                if(a == target) return mid-1;
                else if(b == target) return mid;
                else if(c == target) return mid+1;
                
                
                if((a < b && b < c && b > target) ||
                   (a > b && b < c && a > target) || 
                   (a < b && b > c && c > target))
                {
                        high = mid -1;
                   
                }
                 else low = mid + 1;
            }
        }
        return -1;
    }
};


//GFG POTD solution for 05 May


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends