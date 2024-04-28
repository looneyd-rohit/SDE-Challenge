// Leetcode 1971

// Approach: simple bfs/dfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(visited[node]) continue;
            visited[node] = true;
            // visit neighbours
            for(auto& next: adj[node]){
                if(!visited[next]){
                    q.push(next);
                }
            }
        }
        return visited[destination];
    }
};