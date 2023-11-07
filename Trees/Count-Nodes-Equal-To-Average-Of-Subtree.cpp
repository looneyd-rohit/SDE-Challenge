// Leetcode 2265

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
    int ans = 0;
    pair<int, int> solve(TreeNode* root){
        // base case
        if(root==NULL) return {0, 0};    // <average, count>


        auto left = solve(root->left);

        auto right = solve(root->right);

        int totalSum = root->val + left.first + right.first;
        int totalCnt = 1 + left.second + right.second;

        if(root->val == (totalSum / totalCnt)) ans++;

        return {totalSum, totalCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};