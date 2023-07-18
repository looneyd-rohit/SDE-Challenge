// Leetcode 783

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
    auto solve(TreeNode* root){
        if(!root) return tuple<int, int, int>(1e9, -1e9, 1e9);    // <min value so far, max from left, min from right>
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // compute for current root
        int leftDiff = abs(root->val - get<1>(left));
        int rightDiff = abs(root->val - get<2>(right));
        int newMinDiff = min({get<0>(left), get<0>(right), leftDiff, rightDiff});
        int newMaxFromLeft = max({root->val, get<1>(left), get<1>(right)});
        int newMinFromRight = min({root->val, get<2>(right), get<2>(left)});
        return tuple<int, int, int>(newMinDiff, newMaxFromLeft, newMinFromRight);
    }
    int minDiffInBST(TreeNode* root) {
        auto ans = solve(root);
        return get<0>(ans);
    }
};