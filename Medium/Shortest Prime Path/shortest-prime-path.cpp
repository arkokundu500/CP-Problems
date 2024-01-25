//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Solution {
public:
    // Sieve of Eratosthenes to precompute primes up to n
    void SieveOfEratosthenes(int n, std::vector<bool> &isPrime) {
        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
    }

    // Find the shortest path from Num1 to Num2
    int solve(int Num1, int Num2) {
        const int limit = 9999;
        std::vector<bool> isPrime(limit + 1, true);
        SieveOfEratosthenes(limit, isPrime);

        int ans = 0;
        std::queue<int> q;
        q.push(Num1);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int val = q.front();
                q.pop();

                if (val == Num2) {
                    return ans;
                }

                std::string s = std::to_string(val);

                // Try changing each digit
                for (int j = 0; j < 4; ++j) {
                    char originalDigit = s[j];

                    // Change the digit from 0 to 9
                    for (int k = 0; k < 10; ++k) {
                        if (k == 0 && j == 0) {
                            continue;  // Skip leading zero
                        }

                        s[j] = '0' + k;
                        int temp = std::stoi(s);

                        if (isPrime[temp]) {
                            q.push(temp);
                            isPrime[temp] = false;
                        }
                    }

                    // Restore the original digit
                    s[j] = originalDigit;
                }
            }

            ++ans;
        }

        // If no path is found
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends