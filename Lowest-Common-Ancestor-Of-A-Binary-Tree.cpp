// Leetcode 236
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        if(left != NULL && right != NULL) return root;
        if(left != NULL){
            return left;
        }
        if(right != NULL){
            return right;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};