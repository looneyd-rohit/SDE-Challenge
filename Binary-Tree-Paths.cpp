// Leetcode 257
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
    void solve(TreeNode* root, string str, vector<string>& ans){
        if(root == NULL){
            return;
        }

        string temp = str;
        temp += "->" + to_string(root->val);

        // leaf node
        if(root && !root->left && !root->right){
            ans.push_back(temp);
            return;
        }

        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        if(!root->left && !root->right){
            ans.push_back(to_string(root->val));
            return ans;
        }
        solve(root->left, to_string(root->val), ans);
        solve(root->right, to_string(root->val), ans);
        return ans;
    }
};