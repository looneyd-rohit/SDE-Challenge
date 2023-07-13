// Leetcode 230

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
    int kthSmallest(TreeNode* root, int k) {
        // Inorder Traversal: Morris Traversal
        TreeNode* head = root;
        int ans = 69;
        while(head){
            if(head->left==NULL){
                // k--;
                if(--k==0) ans = head->val;
                head=head->right;
            }else{
                TreeNode* temp = head->left;
                while(temp->right!=NULL && temp->right!=head) temp = temp->right;
                
                if(temp->right!=NULL){
                    // break
                    temp->right = NULL;
                    if(--k==0) ans = head->val;
                    head = head->right;
                }else{
                    // make/join
                    temp->right = head;
                    head = head->left;
                }
            }
        }
        return ans;
    }
};