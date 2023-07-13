// https://practice.geeksforgeeks.org/problems/floor-in-bst/1

// Function to search a node in BST.
void solve(Node* root, int e, int& floor){
    if(!root) return;
    if(root->data==e){
        floor = e;
        return;
    }
    if(root->data>e){
        solve(root->left, e, floor);
    }else{
        floor = root->data;
        solve(root->right, e, floor);
    }
}
int floor(Node* root, int x) {
    int floor = -1;
    solve(root, x, floor);
    return floor;
}