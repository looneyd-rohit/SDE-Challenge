// Leetcode 404

// Approach: recursive call when required
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int left = 0, right = 0;
        if(root->right && root->right->left==NULL && root->right->right==NULL){
            right = 0;
        }else{
            right = sumOfLeftLeaves(root->right);
        }
        if(root->left && root->left->left==NULL && root->left->right==NULL){
            left = root->left->val;
        }else{
            left = sumOfLeftLeaves(root->left);
        }
        return (left + right);
    }
};