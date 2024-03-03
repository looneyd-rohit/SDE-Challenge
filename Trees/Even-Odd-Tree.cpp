// Leetcode 1609

// Approach 1: simple bfs
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
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool is_even = true;
    while (!q.empty()) {
      int sz = q.size();
      int init_val = is_even ? INT_MIN : INT_MAX;
      while (sz--) {
        TreeNode *node = q.front();
        q.pop();
        if (is_even) {
          // even
          if (node->val % 2 == 0)
            return false;
          if (node->val <= init_val)
            return false;
        } else {
          // odd
          if (node->val % 2 == 1)
            return false;
          if (node->val >= init_val)
            return false;
        }
        init_val = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      is_even = !is_even;
    }
    return true;
  }
};

// Approach 2: simple dfs + level
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
  vector<int> arr;
  bool solve(TreeNode *root, int level) {
    if (root == NULL)
      return true;
    int val = root->val;
    bool curr = ((level & 1) ? ((val % 2 == 0) && (val < arr[level]))
                             : ((val % 2 == 1) && (val > arr[level])));
    arr[level] = val;
    return curr && solve(root->left, level + 1) &&
           solve(root->right, level + 1);
  }
  bool isEvenOddTree(TreeNode *root) {
    arr.resize(1e5 + 1, -1);
    for (int i = 0; i <= 1e5; i++) {
      if (i & 1) {
        arr[i] = 1e9;
      } else {
        arr[i] = -1e9;
      }
    }
    return solve(root, 0);
  }
};