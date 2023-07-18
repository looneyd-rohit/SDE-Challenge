// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Solution {
  public:
    int count(struct Node* root){
        if(!root) return 0;
        int left = count(root->left);
        int right = count(root->right);
        return (left + 1 + right);
    }
    bool isCBT(struct Node* root, int index, int nodes){
        if(!root) return true;
        if(index >= nodes) return false;
        bool left = isCBT(root->left, 2*index+1, nodes);
        bool right = isCBT(root->right, 2*index+2, nodes);
        return (left && right);
    }
    bool isHeapOrder(struct Node* root){
        if(!root) return true;
        if(!root->left && !root->right) return true;
        return isHeapOrder(root->left) && 
               isHeapOrder(root->right) && 
               (root->data > root->left->data) &&
               (root->right ? root->data > root->right->data : true);
    }
    bool isHeap(struct Node* tree) {
        // to check if it is heap
        // 1. check for CBT --> to check for CBT we need count of nodes
        // 2. check for heap order
        int nodes = count(tree);
        bool cbt = isCBT(tree, 0, nodes);
        if(cbt){
            return isHeapOrder(tree);
        }else{
            return false;
        }
    }
};