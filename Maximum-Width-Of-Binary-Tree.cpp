// Leetcode 662
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
    int widthOfBinaryTree(TreeNode* root) {
        // deque based approach:
        deque<pair<TreeNode*, unsigned long long>> dq;
        if(root == NULL) return 0;
        dq.push_back({root, 0});
        int ans = 0;
        while(!dq.empty()){
            int sz = dq.size();
            int l = dq.front().second, r = dq.back().second;
            ans = max(ans, r-l+1);
            while(sz--){
                TreeNode* node = dq.front().first;
                unsigned long long no = dq.front().second;
                dq.pop_front();
                TreeNode* left = node->left;
                if(left) dq.push_back({left, 2*no+1});
                TreeNode* right = node->right;
                if(right) dq.push_back({right, 2*no+2});
            }
        }
        return ans;
    }
};