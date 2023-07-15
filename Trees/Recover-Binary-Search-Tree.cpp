// Leetcode 99

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
    void recoverTree(TreeNode* root) {
        // using Morris Traversal
        TreeNode* head = root;
        vector<TreeNode*> nodes;
        TreeNode* prev = new TreeNode(INT_MIN);
        while(head){
            if(head->left==NULL){
                if(head->val < prev->val){
                    nodes.push_back(prev);
                    nodes.push_back(head);
                }
                prev = head;
                head = head->right;
            }else{
                TreeNode* temp = head->left;
                while(temp->right && temp->right!=head) temp = temp->right;
                
                // if connection exists
                if(temp->right==NULL){
                    temp->right = head;
                    head = head->left;
                }else if(temp->right!=NULL){
                    temp->right = NULL;
                    if(head->val < prev->val){
                        nodes.push_back(prev);
                        nodes.push_back(head);
                    }
                    prev = head;
                    head = head->right;
                }
            }
        }
        // cout<<nodes.size()<<endl;
        if(nodes.size() == 2){
            // cout<<nodes[0]->val<<" "<<nodes[1]->val<<endl;
            int t = nodes[0]->val;
            nodes[0]->val = nodes[1]->val;
            nodes[1]->val = t;
        }else{
            int t = nodes[0]->val;
            nodes[0]->val = nodes[3]->val;
            nodes[3]->val = t;
        }
    }
};