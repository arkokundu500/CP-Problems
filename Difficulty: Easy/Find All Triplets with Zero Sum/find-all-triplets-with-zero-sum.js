//{ Driver Code Starts
// Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', () => {
    inputString = inputString.trim().split('\n').map(string => string.trim());
    main();
});

function readLine() { return inputString[currentLine++]; }

// Position this line where user code will be pasted.

function main() {
    let t = parseInt(readLine());
    for (let i = 0; i < t; i++) {
        let arr = readLine().split(' ').map(x => parseInt(x, 10));
        let obj = new Solution();
        let res = obj.findTriplets(arr);
        res = res.sort((x, y) => {
            for (let i = 0; i < 3; i++) {
                if (x[i] !== y[i]) {
                    return x[i] - y[i];
                }
            }
            return 0;
        });
        if (res.length === 0) {
            process.stdout.write('[]\n');
        }
        for (let i = 0; i < res.length; i++) {
            for (let j = 0; j < res[i].length; j++) {
                process.stdout.write(res[i][j] + ' ');
            }
            process.stdout.write('\n');
        }
        process.stdout.write('~\n');
    }
}

// } Driver Code Ends


// User function Template for javascript
// User function Template for javascript
class Solution {
    /**
     * @param {number[]} arr
     * @return {number[][]}
     */
    findTriplets(arr) {
        // write your code here
        const n = arr.length;
        const mp = new Map();
        
        for (let i = n - 1; i > 1; i--) {
            if (!mp.has(arr[i])) {
                mp.set(arr[i], []);
            }
            mp.get(arr[i]).push(i);
        }

        const ans = [];

        for (let j = 1; j < n; j++) {
            if (j >= 2) {
                const indices = mp.get(arr[j]);
                indices.pop();
                if (indices.length === 0) {
                    mp.delete(arr[j]);
                }
            }

            for (let i = 0; i < j; i++) {
                const sum = arr[i] + arr[j];
                if (mp.has(-sum)) {
                    for (const k of mp.get(-sum)) {
                        ans.push([i, j, k]);
                    }
                }
            }
        }

        return ans;
    }
}