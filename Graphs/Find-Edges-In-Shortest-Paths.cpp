// Leetcode 3123

// Approach: compute all shortest edges in a graph from source to destination (bfs/dijkstra) [TLE]
class Solution {
public:
    void find_paths(vector<vector<int> >& paths, vector<int>& path, vector<vector<int>>& parent, int n, int u){
        if (u == -1) {
            paths.push_back(path);
            return;
        }
        for (int par : parent[u]) {
            path.push_back(u);
            find_paths(paths, path, parent, n, par);
            path.pop_back();
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        vector<vector<int>> parent(n);
        parent[0].push_back(-1);
        pq.push({0, 0});
        while(!pq.empty()){
            auto f = pq.top(); pq.pop();
            int node = f.second;
            int cost = f.first;
            for (auto next : adj[node]) {
                if(dist[next.first] > cost + next.second){
                    dist[next.first] = cost + next.second;
                    pq.push({dist[next.first], next.first});
                    parent[next.first].clear();
                    parent[next.first].push_back(node);
                }else if(dist[next.first] == cost + next.second){
                    parent[next.first].push_back(node);
                }
            }
        }
        vector<vector<int> > paths;
        vector<int> path;
        find_paths(paths, path, parent, n, n-1);
        vector<bool> ans;
        set<pair<int, int>> st;
        for (auto v : paths) {
            reverse(v.begin(), v.end());
            for(int k=0; k<v.size()-1; k++){
                st.insert({v[k], v[k+1]});
            }
        }
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            if(st.count({u, v}) || st.count({v, u})){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

// Update: accepted new solution
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> res(edges.size()), visited(n);
        vector<vector<array<int, 2>>> al(n);
        for (int i = 0; i < edges.size(); ++i) {
            al[edges[i][0]].push_back({edges[i][1], i}); // track edge index so we
            al[edges[i][1]].push_back({edges[i][0], i}); // we can update the result
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> path(n, INT_MAX);
        pq.push({0, 0});
        path[0] = 0;
        while(!pq.empty()) {
            auto [len, i] = pq.top(); pq.pop();
            if (len == path[i])
                for (auto [j, e] : al[i])
                    if (len + edges[e][2] < path[j]) {
                        path[j] = len + edges[e][2];
                        pq.push({path[j], j});
                    }
        }
        pq.push({path[n - 1], n - 1}); // backtrack
        while (!pq.empty()) {
            auto [len, i] = pq.top(); pq.pop();
            for (auto [j, e] : al[i])
                if (len - edges[e][2] == path[j]) {
                    if (!visited[j])
                        pq.push({path[j], j});
                    res[e] = visited[j] = true;
                }
        }
        return res;
    }
};