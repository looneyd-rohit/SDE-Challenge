// Leetcode 623

// Approach: using dfs + node insertion logic
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
    TreeNode* solve(TreeNode* root, int l, int val, int depth){
        if(root==NULL) return NULL;

        if(l == depth - 1){
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
        }else{
            root->left = solve(root->left, l+1, val, depth);
            root->right = solve(root->right, l+1, val, depth);
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummy = new TreeNode(1e9);
        dummy->left = root;
        solve(dummy, 0, val, depth);
        return dummy->left;
    }
};