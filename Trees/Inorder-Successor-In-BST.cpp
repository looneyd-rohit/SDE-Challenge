// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* successor;
    void solve(Node* root, Node* x){
        if(root == NULL) return;
        if(root->data <= x->data){
            solve(root->right, x);
        }else{
            this->successor = root;
            solve(root->left, x);
        }
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        this->successor = NULL;
        solve(root, x);
        return this->successor;
    }
};