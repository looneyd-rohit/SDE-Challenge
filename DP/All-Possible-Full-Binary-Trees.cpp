// Leetcode 894

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
    vector<TreeNode*> solve(int num, vector<vector<TreeNode*>>& dp){
        // base case
        if(num == 1){
            TreeNode* t = new TreeNode(0);
            vector<TreeNode*> v;
            v.push_back(t);
            return v;
        }
        
        // dp check
        if(!dp[num].empty()) return dp[num];
        
        // leave atleast one for left subtree, take current node as root, and rest for
        // right sub tree
        // start current from 2nd node
        vector<TreeNode*> ans;
        for(int i=2; i<num; i+=2){
            auto l = solve(i - 1, dp), r = solve(num - i, dp);
            for(auto& left: l){
                for(auto& right: r){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return dp[num] = ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // full binary tree --> each node has exactly two children or zero children
        if(!(n&1)) return {};
        vector<vector<TreeNode*>> dp(n+1);
        return solve(n, dp);
    }
};