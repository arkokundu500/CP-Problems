
class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.size();
        
        // while(s[i] == 0) i++;
        int ans = 0;
        
        int prev = 0;
        for(int i=0 ;i<n ;i++){
            int curr = prev * 10 + (s[i] - '0') * (i+1);
            ans += curr;
            
            prev = curr;
        }
        return ans;
     }
};
//GFG POTD solution for 24 May
