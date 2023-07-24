// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1


class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(){ val = 0; left = NULL; right = NULL; }
    Node(int val){ this->val = val; left = NULL; right = NULL; };
    bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }
};
class Solution
{
	public:
	    void preOrder(Node* root, string temp, vector<string>& ans){
	        if(!root){
	            return;
	        }
	        
	        if(!root->left && !root->right){
	            ans.push_back(temp);
	            return;
	        }
	        
	        temp.push_back('0');
	        preOrder(root->left, temp, ans);
	        temp.pop_back();
	        
	        temp.push_back('1');
	        preOrder(root->right, temp, ans);
	        temp.pop_back();
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, Node> minheap;
		    for(int ind=0; ind<N; ind++){
		        minheap.push(new Node(f[ind]));
		    }
		    while(minheap.size() > 1){
		        auto left = minheap.top(); minheap.pop();
		        auto right = minheap.top(); minheap.pop();
		        Node* root = new Node(left->val + right->val);
		        root->left = left; root->right = right;
		        minheap.push(root);
		    }
		    Node* root = minheap.top();
		    string temp = "";
		    vector<string> ans;
		    preOrder(root, temp, ans);
		    return ans;
		}
};