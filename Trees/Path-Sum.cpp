// Leetcode 112

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == NULL)
      return false;
    if (root->left == NULL && root->right == NULL) {
      // leaf node it is
      return (targetSum - root->val) == 0;
    }
    int val = root->val;
    bool left = hasPathSum(root->left, targetSum - val);
    bool right = hasPathSum(root->right, targetSum - val);
    return left || right;
  }
};