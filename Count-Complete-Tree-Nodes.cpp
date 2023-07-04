// Leetcode 222
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
    int leftMostHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + leftMostHeight(root->left);
    }
    int rightMostHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + rightMostHeight(root->right);
    }
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = leftMostHeight(root->left);
        int rightHeight = rightMostHeight(root->right);
        if(leftHeight != rightHeight){
            return 1 + solve(root->left) + solve(root->right);
        }
        return (1 << (leftHeight+1)) - 1;
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};