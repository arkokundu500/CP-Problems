
class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        
        int n = a1.size();
        unordered_map<int,int> map;
        int maxL = 0;
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i=0; i<n; i++){
            sum1 += a1[i];
            sum2 += a2[i];
            
            if(sum1 == sum2){
                maxL = i+1;
            }
            
            if(map.find(sum1-sum2) != map.end()){
                maxL = max(maxL,i-map[sum1-sum2]);
            }else{
                map[sum1-sum2] = i;
            }
        }
        return maxL;
    }
};