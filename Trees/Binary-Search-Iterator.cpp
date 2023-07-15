// Leetcode 173

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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        // at any point in time keep all the left sided nodes of the tree in the stack
        TreeNode* temp = root;
        while(temp){
            st.push(temp); temp = temp->left;
        }
    }
    
    int next() {
        TreeNode* n = st.top(); st.pop();
        TreeNode* temp = n->right;
        while(temp){
            st.push(temp); temp = temp->left;
        }
        return n->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */