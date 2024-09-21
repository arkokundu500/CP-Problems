/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        vector<int> ans(n,0);
        //BFS level order traversal
        queue<pair<TreeNode*,int>> q;
        if(root)
        q.push({root,0});
        while(q.size()>0){
            TreeNode* top = q.front().first;
            int lvl = q.front().second;
            q.pop();
            ans[lvl] = top-> val;
            if(top->left) q.push({top->left,lvl+1});
            if(top->right) q.push({top->right,lvl+1});
        }
        return ans;
    }
};