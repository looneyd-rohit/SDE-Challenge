// Leetcode 1325

// Approach: deletion in a tree
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
    TreeNode* solve(TreeNode* root, int target){
        if(root == NULL) return NULL;

        int val = root->val;
        if(root->left == NULL && root->right == NULL){
            if(val == target){
                return NULL;
            }else{
                return root;
            }
        }else{
            root->left = solve(root->left, target);
            root->right = solve(root->right, target);

            if(root->left == NULL && root->right == NULL){
                if(val == target){
                    return NULL;
                }
            }
            return root;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
    }
};