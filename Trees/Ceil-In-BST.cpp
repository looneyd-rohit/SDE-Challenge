// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Function to return the ceil of given number in BST.
void solve(Node* root, int input, int& ceil){
    if(!root) return;
    
    if(root->data == input){
        ceil = input;
        return;
    }
    if(root->data < input){
        solve(root->right, input, ceil);
    }else{
        ceil = root->data;
        solve(root->left, input, ceil);
    }
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    int ceil = -1;
    solve(root, input, ceil);
    return ceil;
}