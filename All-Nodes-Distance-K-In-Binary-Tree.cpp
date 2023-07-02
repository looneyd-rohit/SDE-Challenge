// Leetcode 863
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>& umap, vector<int>& ans){
        if(target == NULL || target->val == 501) return;
        if(k == 0){
            ans.push_back(target->val);
            return;
        }
        int temp = target->val;
        target->val = 501;
        solve(umap[target], k-1, umap, ans);
        solve((target->left), k-1, umap, ans);
        solve((target->right), k-1, umap, ans);
        target->val = temp;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // we need to store the parents so that upward movements are possible
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> umap;
        while(!q.empty()){
            TreeNode* front = q.front(); q.pop();
            TreeNode* left = front->left;
            if(left){
                umap[left] = front;
                q.push(left);
            }
            TreeNode* right = front->right;
            if(right){
                umap[right] = front;
                q.push(right);
            }
        }
        // now that we have the parents, we can have recursive calls from the target pointer
        vector<int> ans;
        solve(target, k, umap, ans);
        return ans;
    }
};