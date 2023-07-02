// Interviewbit problem: https://www.interviewbit.com/problems/path-to-given-node/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool mySolve(TreeNode* root, int dest, vector<int>& path){
    if(root == NULL){
        return false;
    }
    
    path.push_back(root->val);
    
    // destination reached
    if(dest == root->val){
        return true;
    }
    if(mySolve(root->left, dest, path)) return true;
    if(mySolve(root->right, dest, path)) return true;
    path.pop_back();
    
    // fallback return
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    if(A==NULL) return path;
    mySolve(A, B, path);
    return path;
}
