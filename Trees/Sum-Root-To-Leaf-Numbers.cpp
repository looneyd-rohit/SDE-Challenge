// Leetcode 129

// Approach: basic tree traversal
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
    int sumNumbers(TreeNode* root, int path=0) {
        if(root==NULL) return 0;

        int val = root->val;
        path = path*10 + val;

        // leaf node check
        if(root->left == NULL && root->right == NULL) return path;

        return sumNumbers(root->left, path) + sumNumbers(root->right, path);
    }
};