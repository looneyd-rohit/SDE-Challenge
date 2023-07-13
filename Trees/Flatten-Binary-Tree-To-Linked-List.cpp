// Leetcode 114
// If you know Morris Traversal then it is cake-walk

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
    void flatten(TreeNode* root) {
        // first study Morris Traversal then this should be pretty easy
        TreeNode* head = root;
        while(head != NULL){
            if(head->left==NULL){
                // no left child, no modifications required at this step
                head = head->right;
            }else{
                // left child exists, put this left child to the right, and
                // iterate same nextwards
                
                // 1. break left connection
                TreeNode* tempLeft = head->left;
                head->left = NULL;
                // 2. break existing right connection
                TreeNode* tempRight = head->right;
                
                // 3. make previous left connection in the right
                head->right = tempLeft;
                
                // 4. join the previous right connection again
                while(tempLeft->right) tempLeft = tempLeft->right;
                tempLeft->right = tempRight;
            }
        }
    }
};