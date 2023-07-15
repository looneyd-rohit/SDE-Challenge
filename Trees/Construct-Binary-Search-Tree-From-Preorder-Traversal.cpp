// Leetcode 1008

// Approach 1: Sorting Preorder to get Inorder

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
    TreeNode* construct(int index, int inLeft, int inRight, vector<int>& inorder, vector<int>& preorder){
        // base case
        if(index >= preorder.size()) return NULL;
        if(inLeft > inRight) return NULL;
        // cout<<index<<" : "<<inLeft<<" to "<<inRight<<endl;
        
        int rootVal = preorder[index];
        TreeNode* root = new TreeNode(rootVal);
        auto it = lower_bound(begin(inorder)+inLeft, begin(inorder)+inRight+1, rootVal);
        
        if(it == inorder.end()) return root;
        
        int rootIndex = it - inorder.begin();
        
        root->left = construct(index+1, inLeft, rootIndex-1, inorder, preorder);
        
        root->right = construct(index+rootIndex-inLeft+1, rootIndex+1, inRight, inorder, preorder);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(begin(inorder), end(inorder));
        return construct(0, 0, n-1, inorder, preorder);
    }
};

// Approach 2: Without sorting, using limits [left, right]

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
    TreeNode* solve(int& index, vector<int>& preorder, int mini, int maxi){
        // base case
        if(index >= preorder.size()) return NULL;
        
        int rootVal = preorder[index];
        if(mini < rootVal && rootVal < maxi){
            TreeNode* root = new TreeNode(rootVal);
            index++;
            root->left = solve(index, preorder, mini, rootVal);
            root->right = solve(index, preorder, rootVal, maxi);
            return root;
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(index, preorder, INT_MIN, INT_MAX);
    }
};