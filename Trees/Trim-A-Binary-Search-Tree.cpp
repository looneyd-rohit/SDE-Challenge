// Leetcode 669

// Approach 1: Brute Force type, this will work even in a simple binary tree, since
// we are never utilizing the property of bst (smaller on left, larger on right)

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        
        
        if(root->val < low || root->val > high){
            // eliminate this root
            // we call trimBST again for left and right, since it may happen that
            // not only current root, but below childs needs to be deleted
            TreeNode* tempLeft = trimBST(root->left, low, high);
            TreeNode* tempRight = trimBST(root->right, low, high);
            root->left = root->right = NULL;
            if(!tempLeft) return tempRight;
            if(!tempRight) return tempLeft;
            // take the left subtree and make it the next root part, and join the right subtree
            // to the end of the left subtree
            TreeNode* temp = tempLeft;
            while(temp->right) temp = temp->right;
            temp->right = tempRight;
            return tempLeft;
        }else{
            // lies in range, continue searching
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};

// Approach 2: using bst property we can shorten the code

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        
        // utilising the property of binary search tree, that nodes on left are smaller
        // and nodes on right are greater, we can optimize the solution
        if(root->val < low) return trimBST(root->right, low, high);    // all smaller nodes in left
        if(root->val > high) return trimBST(root->left, low, high);    // all larger nodes in right
        // if none
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};