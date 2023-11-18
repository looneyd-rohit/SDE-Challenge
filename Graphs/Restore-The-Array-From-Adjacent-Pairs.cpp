// Leetcode 1743

class Solution {
public:
    vector<int> ans;
    int dfs(int node, unordered_map<int, list<int>>& adj, unordered_set<int>& visited){
        visited.insert(node);
        bool hasNext = false;
        for(auto& next: adj[node]){
            if(visited.find(next)==visited.end()){
                hasNext = true;
                int val = dfs(next, adj, visited);
                if(val!=-1e9) return val;
            }
        }
        if(!hasNext) return node;
        return -1e9;
    }
    void traverse(int node, unordered_map<int, list<int>>& adj, unordered_set<int>& visited){
        visited.insert(node);
        ans.push_back(node);
        for(auto& next: adj[node]){
            if(visited.find(next)==visited.end()){
                traverse(next, adj, visited);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int, list<int>> adj;
        for(auto& edge: adjacentPairs){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // find the start node doing any dfs from any of the start nodes
        unordered_set<int> visited;
        int start = dfs(adj.begin()->first, adj, visited);
        unordered_set<int> visited2;
        traverse(start, adj, visited2);
        return ans;
    }
};