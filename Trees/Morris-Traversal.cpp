// Inorder

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
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal:
        vector<int> inorder;
        while(root!=NULL){
            if(root->left == NULL){
                inorder.push_back(root->val);
                root = root->right;
            }else{
                // left child exists, create/delete threads
                TreeNode* temp = root->left;
                while(temp->right!=NULL && temp->right!=root){
                    temp = temp->right;
                }
                
                // if thread does not exist, create it
                if(temp->right==NULL){
                    temp->right = root;
                    root = root->left;
                }
                // else if thread exists, this means, these are visited,
                // time to go to right subtree of root and delete threads
                else{
                    temp->right = NULL;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return inorder;
    }
};

// Preorder

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
    vector<int> preorderTraversal(TreeNode* root) {
        // Morris Traversal
        vector<int> preorder;    // Node Left Right
        while(root!=NULL){
            if(root->left==NULL){
                // move to right
                preorder.push_back(root->val);
                root=root->right;
            }else{
                // left child exists
                TreeNode* temp = root->left;
                while(temp->right!=NULL && temp->right!=root) temp = temp->right;
                
                // if thread does not exist
                if(temp->right==NULL){
                    temp->right = root;
                    // since it is preorder, first take root value then move to left subtree
                    preorder.push_back(root->val);
                    root = root->left;
                }else{
                    // thread already exists, delete it, second time traversal
                    temp->right = NULL;
                    root = root->right;
                }
            }
        }
        return preorder;
    }
};