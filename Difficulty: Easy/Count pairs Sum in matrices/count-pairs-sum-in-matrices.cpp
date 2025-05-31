
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int target) {
        // code here
        int n=a.size();
        int i=0;
        int j=0;
        int x=n-1;
        int y=n-1;
        int cnt=0;
        while(i<n && x>=0){
            if(a[i][j]+b[x][y]==target){
                cnt++;
                j++;
                if(j==n){
                    i++;
                    j=0;
                }
                
            }
            else if(a[i][j]+b[x][y]<target){
                j++;
                if(j==n){
                    i++;
                    j=0;
                }
            }
            else{
                y--;
                if(y==-1){
                    x--;
                    y=n-1;
                }
            }
        }
        return cnt;
        
    }
};