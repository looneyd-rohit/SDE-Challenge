// Leetcode 2685
// [IMP]: Simple DFS with count logic
class Solution {
public:
    pair<int, int> dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        pair<int, int> p = make_pair(1, adj[node].size());
        for(auto& next: adj[node]){
            if(!visited[next]){
                pair<int, int> p2 = dfs(next, adj, visited);
                p.first += p2.first;
                p.second += p2.second;
            }
        }
        return p;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // count the nodes and edges for each component
        // construct the graph
        unordered_map<int, list<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                pair<int, int> p = dfs(i, adj, visited);
                int nodeCount = p.first, edgeCount = p.second;
                if((nodeCount * (nodeCount-1)) == edgeCount){
                    ans++;
                }
            }
        }
        return ans;
    }
};