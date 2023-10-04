#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v=0){
        this->val = v;
        this->left = NULL; this->right = NULL;
    }
};

class point{
    public:
    Node* node;
    int mini;
    int maxi;
    point(Node* node=NULL, int mini=INT_MIN, int maxi=INT_MAX): node(node), mini(mini), maxi(maxi) {}
};

Node* build(vector<int>& level){
    queue<point*> q;
    q.push(new point());
    int index = 0;
    Node* root = NULL;
    while(!q.empty()){
        auto f = q.front(); q.pop();
        if(index >= level.size()) break;
        int v = level[index];
        if(v < f->mini || v > f->maxi) continue;
        Node* head = new Node(v);
        cout<<head->val<<" ";
        if(f->node == NULL){
            // first node --> root
            root = head;
        }else{
            // if not root, node, then make appropriate connections
            if(v < f->node->val){
                // cout<<"is lesser than maxi "<<f->maxi<<" "<<f->node->val<<endl;
                f->node->left = head;
            }else if(v > f->node->val){
                // cout<<"is more than mini "<<f->mini<<" "<<f->node->val<<endl;
                f->node->right = head;
            }
        }
        // push to queue
        q.push(new point(head, f->mini, min(v, f->maxi)));
        q.push(new point(head, max(v, f->mini), f->maxi));
        index++;
    }
    cout<<endl;
    return root;
}



int main(){
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(5);
    arr.push_back(11);
    // arr.push_back(-1);
    // arr.push_back(-1);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(7);
    // arr.push_back(-1);
    Node* root = build(arr);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front(); q.pop();
        if(node == NULL) continue;
        cout<<node->val<<" ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    cout<<endl;
    return 0;
}