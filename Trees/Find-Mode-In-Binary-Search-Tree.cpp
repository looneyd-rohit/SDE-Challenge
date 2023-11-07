// Leetcode 501

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
    int currFreq = 0, maxFreq = 0, currNum = 0;
    vector<int> result;
    void dfs(TreeNode* root){
        if(root==NULL) return;

        // left call
        dfs(root->left);

        // check for equality with current number
        if(currNum!=root->val){
            currNum = root->val;
            currFreq = 1;
        }else{
            currFreq++;
        }

        // check for maxFreq that can be achieved
        if(currFreq > maxFreq){
            maxFreq = currFreq;
            // since maxFreq is updated, update the result
            result = {currNum};
        }else if(currFreq == maxFreq){
            // add if currFreq and maxFreq is same
            result.push_back(currNum);
        }
        
        // right call
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return result;
    }
};