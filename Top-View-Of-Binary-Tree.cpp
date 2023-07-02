// Map based approach:
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // using map --> simialar to vertical order traversal
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp; 
        queue<tuple<Node*, int>> q;
        q.push(tuple<Node*, int>(root, 0));
        while(!q.empty()){
            auto f = q.front(); q.pop();
            Node* node = get<0>(f);
            int vertical = get<1>(f);
            if(mp.find(vertical)==mp.end()){
                mp[vertical] = node->data;
            }
            Node* left = node->left;
            if(left) q.push(tuple<Node*, int>(left, vertical-1));
            Node* right = node->right;
            if(right) q.push(tuple<Node*, int>(right, vertical+1));
        }
        // now traverse the map and find the solution
        for(auto& e: mp){
            int vertical = e.first;
            // only take the first element of each unique vertical and level
            int element = e.second;
            ans.push_back(element);
        }
        return ans;
    }

};


