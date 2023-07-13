// Leetcode 105

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
    TreeNode* solve(int preInd, int inLeft, int inRight, vector<int>& preorder, vector<int>& inorder){
        // base case, index out of bounds
        if(preInd >= preorder.size()) return NULL;
        
        int rootVal = preorder[preInd];
        int rootInd = -1;
        // find the rootInd
        for(int i=inLeft; i<=inRight; i++){
            if(inorder[i]==rootVal){
                rootInd = i;
                break;
            }
        }
        // now that we have the inorder index call for both left and right parts and join to
        // the tree
        // if not found
        if(rootInd == -1) return NULL;
        // if found
        TreeNode* root = new TreeNode(rootVal);
        // the left part starts right after root node
        root->left = solve(preInd+1, inLeft, rootInd-1, preorder, inorder);
        // the right part starts after the left ends
        root->right = solve(preInd+(rootInd-inLeft+1), rootInd+1, inRight, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return solve(0, 0, n-1, preorder, inorder);
    }
};