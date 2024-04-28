// Leetcode 988

// Approach 1: dfs + string forming
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
    string ans;
    int level;
    void solve(TreeNode* root, int l=0, string path=""){
        if(root==NULL) return;
        path = (char)(root->val+97) + path;
        if(root->left==NULL && root->right==NULL){
            if(ans == "" || ans > path) ans = path;
        }
        solve(root->left, l+1, path);
        solve(root->right, l+1, path);
        path.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        level = 1e9;
        solve(root, 0, "");
        return ans;
    }
};

// Approach 2: bfs + string formation
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
    string ans;
    int level;
    void solve(TreeNode* root, int l=0, string path=""){
        if(root==NULL) return;
        path = (char)(root->val+97) + path;
        if(root->left==NULL && root->right==NULL){
            if(ans == "" || ans > path) ans = path;
        }
        solve(root->left, l+1, path);
        solve(root->right, l+1, path);
        path.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        // level = 1e9;
        // solve(root, 0, "");
        queue<pair<TreeNode*, string>> q;
        if(root==NULL) return ans;
        string a = "";
        q.push({root, a + (char)(root->val+97)});
        while(!q.empty()){
            auto f = q.front(); q.pop();
            TreeNode* node = f.first;
            string str = f.second;
            if(node->left==NULL && node->right==NULL){
                if(ans == "" || ans > str) ans = f.second;
            }
            if(node->left){
                string temp = (char)(node->left->val + 97) + str;
                q.push({node->left, temp});
            }
            if(node->right){
                string temp = (char)(node->right->val + 97) + str;
                q.push({node->right, temp});
            }
        }
        return ans;
    }
};