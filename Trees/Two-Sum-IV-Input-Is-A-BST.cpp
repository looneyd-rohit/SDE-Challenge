// Leetcode 653

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
    stack<TreeNode*> st1, st2;
    void init(TreeNode* root) {
        // at any point in time keep all the left sided nodes of the tree in the stack
        TreeNode* temp = root;
        while(temp){
            st1.push(temp); temp = temp->left;
        }
        temp = root;
        while(temp){
            st2.push(temp); temp = temp->right;
        }
    }
    
    int next() {
        TreeNode* n = st1.top(); st1.pop();
        TreeNode* temp = n->right;
        while(temp){
            st1.push(temp); temp = temp->left;
        }
        return n->val;
    }
    
    int prev(){
        TreeNode* n = st2.top(); st2.pop();
        TreeNode* temp = n->left;
        while(temp){
            st2.push(temp); temp = temp->right;
        }
        return n->val;
    }
    
    bool hasNext() {
        return !st1.empty();
    }
    
    bool hasPrev() {
        return !st2.empty();
    }
    bool findTarget(TreeNode* root, int k) {
        this->init(root);
        int nextPtr = this->next();
        int prevPtr = this->prev();
        int sum = nextPtr + prevPtr;
        if(sum == k && nextPtr!=prevPtr) return true;
        while(this->hasNext() && this->hasPrev()){
            if(sum == k && nextPtr!=prevPtr) return true;
            else if(sum > k) prevPtr = this->prev();
            else nextPtr = this->next();
            sum = nextPtr + prevPtr;
        }
        return sum == k && nextPtr!=prevPtr;
    }
};