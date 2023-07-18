// Leetcode 116

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // can be done using a level order traversal
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto f = q.front(); q.pop();
            if(f == NULL){
                // end of current level reached
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                f->next = q.front();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return root;
    }
};