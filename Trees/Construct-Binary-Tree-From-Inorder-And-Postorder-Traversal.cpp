// Leetcode 106

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
    TreeNode* solve(int postInd, int inLeft, int inRight, vector<int>& postorder, vector<int>& inorder){
        // base case, index out of bounds
        if(postInd >= postorder.size()) return NULL;
        
        int rootVal = postorder[postInd];
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
        // the right part starts right after root node
        root->right = solve(postInd-1, rootInd+1, inRight, postorder, inorder);
        // the left part starts after the right ends
        root->left = solve(postInd-(inRight-rootInd+1), inLeft, rootInd-1, postorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return solve(n-1, 0, n-1, postorder, inorder);
    }
};