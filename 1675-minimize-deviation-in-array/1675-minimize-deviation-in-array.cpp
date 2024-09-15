class Solution {
public:
    int minimumDeviation(std::vector<int>& nums) {
        
        std::set<int> s;
        
        // Adjust all numbers: make odd numbers even by multiplying by 2
        for (int i : nums) {
            if (i % 2 == 1) i *= 2;
            s.insert(i);
        }
        
        int diff = INT_MAX;
        
        // Loop to reduce the maximum number as much as possible
        while (true) {
            int maxVal = *s.rbegin();  // Maximum value in the set
            int minVal = *s.begin();   // Minimum value in the set
            
            diff = std::min(diff, maxVal - minVal);  // Update the minimum difference
            
            if (maxVal % 2 == 0) {
                s.erase(maxVal);            // Remove the current maximum
                s.insert(maxVal / 2);       // Add its half to the set
            } else {
                break;                      // If the max value is odd, stop
            }
        }
        
        return diff;
    }
};
