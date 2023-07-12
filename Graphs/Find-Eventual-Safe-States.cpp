// Leetcode 802
// Typical bfs, gives tle on dfs without using dfsvisited array

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // typical topo sort problem: using bfs
        int n = graph.size();
        // we need to reverse the edges, since we are required to only find the topo sort
        // of those small parts within the graph which don't fall in a cycle,
        // to achieve this we need to reverse the edges, because on reversing the
        // terminal nodes which used to have 0 outdegree will now have 0 indegree
        // and we can start from them toward others, and if others could not reach 0 indegree
        // they are part of cycle which means if you are part of cycle you in/out degrees
        // aren't affected
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto& node: graph[i]){
                adj[node].push_back(i);
                indegree[i]++;
            }
        }
        
        vector<int> ans;
        
        // we need a queue for bfs traversal
        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            // visit the neighbours
            for(auto& next: adj[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};

// Slight optimization of dfs and it runs smoothly

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
        for(auto& next: graph[node]){
            if(!visited[next]){
                if(dfs(next, graph, visited, dfsVisited)){
                    return true;
                }
            }else if(dfsVisited[next]){
                return true;
            }
        }
        return dfsVisited[node] = false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // typical topo sort problem: using dfs
        int n = graph.size();
        vector<bool> visited(n, false);
        // we need dfsVisited array to find if there exists a cycle in this directed
        // graph, using dfs
        vector<bool> dfsVisited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, graph, visited, dfsVisited);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!dfsVisited[i]){
                ans.push_back(i);
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};