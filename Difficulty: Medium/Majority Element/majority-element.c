//{ Driver Code Starts
// Initial Template for C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends

// User function Template for C

#define SIZE 1e5 + 1
int majorityElement(int arr[], int n) {
    // code here
    int* freq = (int*)calloc(SIZE, sizeof(int));
    
    for (int i = 0; i < n; ++i)
        freq[arr[i]]++;
    for (int i = 0; i < SIZE; i++) {
        if (freq[i] > n / 2)
            return i;
    }
    return -1;
}



//{ Driver Code Starts.

int main() {
    char ts[1001];
    fgets(ts, sizeof(ts), stdin);
    int t = atoi(ts);
    while (t--) {

        char *line = NULL;
        size_t len = 0;
        long read = getline(&line, &len, stdin);

        int *nums = (int *)malloc(1000000 * sizeof(int));
        int n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[n++] = atoi(token);
            token = strtok(NULL, " "); // Get the next token
        }
        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Check if the array is sorted using the previously defined function
        int ans = majorityElement(brr, n);
        printf("%d\n", ans);
        // Output 'true' if the array is sorted, 'false' otherwise

        printf("%s\n", "~");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends