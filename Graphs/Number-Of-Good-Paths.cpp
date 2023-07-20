// Leetcode 2421

// Brute Force: Form a new graph everytime with maximum node excluded starting from
// max-nodes to min-nodes
class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<int>& vals, vector<bool>& visited, int k, int& c){
        visited[node] = true;
        if(vals[node] == k) c++;
        for(auto& next: adj[node]){
            if(!visited[next]){
                dfs(next, adj, vals, visited, k, c);
            }
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // brute force approach: store all the node values in sorted order
        // take the maximum among them and then construct a graph and find the number of nodes
        // with the maximum value, then remove the node from that list and construct a graph without
        // those that were removed and perform traversal again on the graph and so on...
        int n = vals.size();
        set<int, greater<int>> st;
        for(auto& e: vals) st.insert(e);
        int count = 0;
        for(auto& maxi: st){
            // construct a new graph
            unordered_map<int, list<int>> adj;
            for(auto& edge: edges){
                int u = edge[0], v = edge[1];
                if(vals[u] > maxi || vals[v] > maxi) continue;
                adj[u].push_back(v); adj[v].push_back(u);
            }
            
            // do a dfs and count
            vector<bool> visited(n, false);
            for(int i=0; i<n; i++){
                int c = 0;
                dfs(i, adj, vals, visited, maxi, c);
                int pdt = c * (c-1) / 2;
                count += pdt;
            }
        }
        return n + count;
    }
};

// [IMP]: DSU very nice approach, one of the best, stitching concept
class Solution {
public:
    vector<int> parent, rank;
    void init(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        // path compression
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return ;
        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u]++;
        }else if(rank[u] < rank[v]){
            parent[u] = v;
        }else{
            parent[v] = u;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // dsu based approach: start from lower value nodes and keep making them active and construct
        // the paths
        int n = vals.size();
        map<int, list<int>> strength;    // stores <strength, <list of nodes>>
        for(int i=0; i<n; i++){
            strength[vals[i]].push_back(i);
        }
        // construct the adjacency list
        unordered_map<int, list<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // init the dsu
        init(n);
        int count = 0;
        vector<bool> active(n, false);
        for(auto& e: strength){
            int s = e.first;
            
            // map to store different parent nodes
            unordered_map<int, int> parentChildMap;
            
            // make all the nodes with strength s active
            // make connections/merge if active nearby
            for(auto& el: e.second){
                active[el] = true;
                for(auto& next: adj[el]){
                    if(active[next]){
                        unionByRank(el, next);
                    }
                }
            }
            
            // get nodes with same parent
            for(auto& el: e.second){
                parentChildMap[findParent(el)]++;
            }
            
            // count the good paths
            for(auto& e: parentChildMap){
                int k = e.second;
                int pdt = k * (k - 1) / 2;
                count += pdt;
            }
        }
        return n + count;
    }
};