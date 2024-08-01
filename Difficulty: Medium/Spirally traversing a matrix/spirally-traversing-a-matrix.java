//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int r = sc.nextInt();
            int c = sc.nextInt();

            int matrix[][] = new int[r][c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.spirallyTraverse(matrix);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution {
    public ArrayList<Integer> spirallyTraverse(int matrix[][]) {
        // code here
        int n=matrix.length,m=matrix[0].length;
        ArrayList<Integer> ans=new ArrayList<>();
        int top=0,bottom=n-1,left=0,right=m-1;
        
        while(left<=right && top<=bottom){
            
            //left to right
            for(int i=left;i<=right;i++){
                ans.add(matrix[top][i]);
            }
            top++;
            
            //top to bottom
            for(int i=top;i<=bottom;i++){
                ans.add(matrix[i][right]);
            }
            right--;
            
            //handling the testCase for (One row _or_ One column) eg: {1,2,3}=>1 2 3 2 1 and eg: {{1},{2},{3}} => 1 2 3 2 
            if(!(left<=right && top<=bottom)) break;
            
            //right to left
            for(int i=right;i>=left;i--){
                ans.add(matrix[bottom][i]);
            }
            bottom--;
            
            //bottom to top
            for(int i=bottom;i>=top;i--){
                ans.add(matrix[i][left]);
            }
            left++;
        }
        return ans; 
    }
}
