// Leetcode 1038

// Approach 1: using recursion
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
    int sum;
    void solve(TreeNode* root){
        if(root == NULL) return;
        solve(root->right);
        root->val += sum;
        sum = root->val;
        solve(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        solve(root);
        return root;
    }
};

// Appproach 2: using morris traversal
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
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* head = root;
        int sum = 0;
        // morris traversal for [right - node - left]
        while(head){
            if(head->right == NULL){
                head->val += sum;
                sum = head->val;
                head = head->left;
            }else{
                TreeNode* temp = head->right;
                while(temp->left!=NULL && temp->left!=head) temp = temp->left;
                
                // add or remove threads
                if(temp->left){
                    // thread exists, remove it
                    temp->left = NULL;
                    head->val += sum;
                    sum = head->val;
                    head = head->left;
                }else{
                    // thread does not exist, make it
                    temp->left = head;
                    head = head->right;
                }
            }
        }
        return root;
    }
};