// queue based approach:
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        ans.push_back(q.front()->data);
        while(sz--){
            auto node = q.front(); q.pop();
            Node* left = node->left;
            if(left) q.push(left);
            Node* right = node->right;
            if(right) q.push(right);
        }
    }
    return ans;
}