// Leetcode 310

// [IMP] Approach: observation + bfs from leaves
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // perform bfs from leaves
        // note: there will be atmost two nodes which will have minimum height
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[v]++;
            indegree[u]++;
        }
        int remaining = n;
        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i]<=1) q.push(i);
        while(remaining > 2){
            int sz = q.size();
            remaining -= sz;
            while(sz--){
                int node = q.front(); q.pop();
                // visit neighbours
                for(auto& next: adj[node]){
                    indegree[next]--;
                    if(indegree[next]==1){
                        q.push(next);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};