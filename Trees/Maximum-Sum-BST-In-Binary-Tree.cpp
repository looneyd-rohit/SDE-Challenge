// Leetcode 1373

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
    int ans;
    auto solve(TreeNode* root){
        if(!root) return tuple<int, int, int>(0, INT_MAX, INT_MIN);    // <sum, minimum of right, maximum of left>
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(get<2>(left) < root->val && root->val < get<1>(right)){
            // it is a bst
            int new_sum = get<0>(left) + root->val + get<0>(right);
            ans = max(ans, new_sum);
            int new_mini = min({get<1>(left), root->val, get<1>(right)});
            int new_maxi = max({get<2>(left), root->val, get<2>(right)});
            return tuple<int, int, int>(new_sum, new_mini, new_maxi);
        }
        return tuple<int, int, int>(0, INT_MIN, INT_MAX);
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};