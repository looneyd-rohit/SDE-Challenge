// Leetcode 95

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
    map<pair<int, int>, vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int i, int j){
        // base case
        if(i > j) return dp[{i, j}] = {NULL};
        if(i == j) return dp[{i, j}] = {new TreeNode(i)};

        // dp check
        if(dp.find({i, j})!=dp.end()) return dp[{i, j}];

        vector<TreeNode*> ans;
        for(int k=i; k<=j; k++){
            vector<TreeNode*> left = solve(i, k-1);
            vector<TreeNode*> right = solve(k+1, j);
            for(TreeNode* l: left){
                for(TreeNode* r: right){
                    TreeNode* root = new TreeNode(k);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return dp[{i, j}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};