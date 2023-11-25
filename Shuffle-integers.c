class Solution {
public:
    void shuffleArray(int arr[], int n) {
        int mid = n / 2;
        for (int i = 0; i < mid; i++) {
            std::rotate(arr + 2 * i + 1, arr + mid + i, arr + mid + i + 1);
        }
    }
};

//https://www.geeksforgeeks.org/problems/shuffle-integers2401/1
