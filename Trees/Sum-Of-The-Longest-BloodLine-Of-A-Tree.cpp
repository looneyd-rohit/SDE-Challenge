// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
public:
    int maxLen, maxSum;
    void solve(Node* root, int len, int sum){
        if(!root){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }else if(len == maxLen){
                maxSum = max(maxSum, sum);
            }
            return;
        }
        solve(root->left, len+1, sum+root->data);
        solve(root->right, len+1, sum+root->data);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        maxLen = 0, maxSum = 0;
        solve(root, 0, 0);
        return maxSum;
    }
};