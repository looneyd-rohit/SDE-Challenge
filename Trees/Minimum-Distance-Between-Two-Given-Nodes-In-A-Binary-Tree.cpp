// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* findLCA(Node* root, int p, int q){
        if(!root) return NULL;
        if(root->data == p || root->data == q){
            return root;
        }
        auto left = findLCA(root->left, p, q);
        auto right = findLCA(root->right, p, q);
        if(left && right) return root;
        else if(left) return left;
        else return right;
    }
    int findDist(Node* root, int a){
        if(!root) return 1e9;
        if(root->data == a) return 0;
        int left = findDist(root->left, a);
        int right = findDist(root->right, a);
        return 1 + min(left, right);
    }
    int findDist(Node* root, int a, int b) {
        // find the lca
        auto lca = findLCA(root, a, b);
        int d1 = findDist(lca, a);
        int d2 = findDist(lca, b);
        return d1 + d2;
    }
};