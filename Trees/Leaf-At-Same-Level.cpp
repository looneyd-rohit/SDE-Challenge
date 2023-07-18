// https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
  public:
    /*You are required to complete this method*/
    int firstLevel;
    bool solve(Node* root, int currLevel){
        if(!root) return true;
        if(!root->left && !root->right){
            if(firstLevel==-1){
                firstLevel = currLevel;
                return true;
            }
            return currLevel == firstLevel;
        }
        return solve(root->left, currLevel+1) && solve(root->right, currLevel+1);
    }
    bool check(Node *root)
    {
        firstLevel = -1;
        return solve(root, 0);
    }
};