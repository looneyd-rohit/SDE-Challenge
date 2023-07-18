// Leetcode 872

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
    void leafNodes(TreeNode* root, vector<int>& store){
        if(!root) return;
        if(!root->left && !root->right){
            store.push_back(root->val);
            return;
        }
        leafNodes(root->left, store);
        leafNodes(root->right, store);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1, store2;
        leafNodes(root1, store1);
        leafNodes(root2, store2);
        return store1 == store2;
    }
};