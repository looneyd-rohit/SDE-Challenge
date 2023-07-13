// Leetcode 450
// [IMP]: Full recursive code

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
    TreeNode* makeReconnections(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rootRightChild = root->right;
        TreeNode* rootLeftChild = root->left;
        TreeNode* temp = rootLeftChild;
        while(temp->right) temp = temp->right;
        temp->right = rootRightChild;
        return rootLeftChild;
    }
    TreeNode* solve(TreeNode* root, int key){
        // base case
        if(!root) return NULL;
        if(root->val == key){
            // delete it
            return makeReconnections(root);
        }else if(root->val > key){
            root->left = solve(root->left, key);
            return root;
        }else{
            root->right = solve(root->right, key);
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        // search for the node and then delete
        return solve(root, key);
    }
};