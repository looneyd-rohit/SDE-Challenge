// Leetcode 652

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
    string solve(TreeNode* root, unordered_map<string, int>& hash, vector<TreeNode*>& ans){
        // base case
        if(!root) return "NULL";
        string currentTree = to_string(root->val) + "->" + solve(root->left, hash, ans) + "->" + solve(root->right, hash, ans);
        if(hash[currentTree]==1){
            // duplicacy exists if count > 1, but we push only once as only one of
            // the duplicates is needed, so push only when first duplicate found
            ans.push_back(root);
        }
        hash[currentTree]++;
        return currentTree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // brute force gives TLE, so we stringify every subtree and store it
        // because to directly compare we will required n2 * n ~ time
        unordered_map<string, int> hash;
        vector<TreeNode*> ans;
        solve(root, hash, ans);
        return ans;
    }
};