// https://practice.geeksforgeeks.org/problems/burning-tree/1

// BFS based approach:

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // we need to store the parent
        unordered_map<Node*, Node*> umap;
        queue<Node*> q;
        q.push(root);
        Node* start = NULL;
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            if(front->data == target) start = front;
            Node* left = front->left;
            Node* right = front->right;
            if(left){
                umap[left] = front;
                q.push(left);
            }
            if(right){
                umap[right] = front;
                q.push(right);
            }
        }
        // now traverse from the target until the tree becomes empty
        q.push(start);
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* front = q.front(); q.pop();
                if(front->data == 696969) continue;
                front->data = 696969;
                Node* left = front->left;
                Node* right = front->right;
                Node* parent = umap[front];
                if(left && left->data!=696969) q.push(left);
                if(right && right->data!=696969) q.push(right);
                if(parent && parent->data!=696969) q.push(parent);
            }
            time++;
        }
        return time-1;
    }
};

// DFS based approach:

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int solve(Node* start, unordered_map<Node*, Node*>& umap){
        if(start == NULL || start->data==696969) return 0;
        
        start->data = 696969;
        
        int leftChild = solve(start->left, umap);
        int rightChild = solve(start->right, umap);
        int parent = solve(umap[start], umap);
        
        return 1 + max({leftChild, rightChild, parent});
    }
    int minTime(Node* root, int target) 
    {
        // we need to store the parent
        unordered_map<Node*, Node*> umap;
        queue<Node*> q;
        q.push(root);
        Node* start = NULL;
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            if(front->data == target) start = front;
            Node* left = front->left;
            Node* right = front->right;
            if(left){
                umap[left] = front;
                q.push(left);
            }
            if(right){
                umap[right] = front;
                q.push(right);
            }
        }
        // now traverse from the target until the tree becomes empty
        return solve(start, umap)-1;
    }
};