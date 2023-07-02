// Map based approach
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, map<int, int>> mp;
        // we need the last level element for each vertical
        queue<tuple<Node*, int, int>> q;
        q.push(tuple<Node*, int, int>(root, 0, 0));
        while(!q.empty()){
            auto front = q.front(); q.pop();
            Node* node = get<0>(front);
            int vertical = get<1>(front), level = get<2>(front);
            mp[vertical][level] = node->data;
            Node* left = node->left;
            if(left) q.push(tuple<Node*, int, int>(left, vertical-1, level+1));
            Node* right = node->right;
            if(right) q.push(tuple<Node*, int, int>(right, vertical+1, level+1));
        }
        // now traverse the map and store the elements
        for(auto& e: mp){
            int vertical = e.first;
            // take the last level element for each vertical
            int element = (e.second.rbegin())->second;
            ans.push_back(element);
        }
        return ans;
    }
};