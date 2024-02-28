// Leetcode 513

// Approach 1: find height -> do bfs
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
  int height(TreeNode *root) {
    if (root == NULL)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
  int findBottomLeftValue(TreeNode *root) {
    int h = height(root);
    queue<pair<TreeNode *, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      TreeNode *node = f.first;
      int level = f.second;
      if (level == h)
        return node->val;
      if (node->left) {
        q.push({node->left, level + 1});
      }
      if (node->right) {
        q.push({node->right, level + 1});
      }
    }
    return -1;
  }
};

// Approach 2: simple bfs
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
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int left_last_row = -1;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      left_last_row = f->val;
      if (f->right) {
        q.push(f->right);
      }
      if (f->left) {
        q.push(f->left);
      }
    }
    return left_last_row;
  }
};