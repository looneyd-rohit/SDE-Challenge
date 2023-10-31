// Leetcode 515

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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        int maxi = INT_MIN;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            if(f == NULL){
                ans.push_back(maxi);
                maxi = INT_MIN;
                if(!q.empty()) q.push(NULL);
            }else{
                maxi = max(maxi, f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return ans;
    }
};