// Leetcode 979

// Approach: recursive approach + using absolute value to distribute coins
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
    int moves;
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        moves += (abs(left) + abs(right));

        return (left + root->val + right - 1);
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        solve(root);
        return moves;
    }
};