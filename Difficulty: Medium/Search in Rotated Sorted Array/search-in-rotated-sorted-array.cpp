//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Get the size of the array
        int n = arr.size();
        // Initialize the low and high pointers
        int low = 0;
        int high = n - 1;
        // Binary search loop
        while(low <= high) {
        // Calculate the mid index
        int mid = (low + high) / 2;
    
        // If the key is found at mid, return the index
        if(arr[mid] == key) return mid;
    
        // Check if the left half is sorted
        else if(arr[low] <= arr[mid]) {
            // If the key lies in the sorted left half, adjust the high pointer
            if(arr[low] <= key && key <= arr[mid]) high = mid - 1;
            // Otherwise, adjust the low pointer to search in the right half
            else low = mid + 1;
        }
        // If the right half is sorted
        else {
            // If the key lies in the sorted right half, adjust the low pointer
            if(arr[high] >= key && key >= arr[mid]) low = mid + 1;
            // Otherwise, adjust the high pointer to search in the left half
            else high = mid - 1;
        }
    }
    // If the key is not found, return -1
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends