// Leetcode 947
// Approach 1: Brute Force DFS

class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones, vector<bool>& visited){
        visited[node] = true;
        for(int i=0; i<stones.size(); i++){
            if(!visited[i]){
                if(stones[node][0]==stones[i][0] || stones[node][1]==stones[i][1]){
                    dfs(i, stones, visited);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        // dfs based approach:
        int n = stones.size();
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            // if not visited then do a dfs from current node
            dfs(i, stones, visited);
            components++;
        }
        return n - components;
    }
};

// Approach 2: DSU [IMP] Pattern for union find approaches (union by Rank + union by size)
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
        if(u == v) return;
        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u]++;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[u] = v;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        // dsu based approach: considering every row and every column as a set of numbers
        // upon which we will perform union
        int n = stones.size();
        // init the dsu
        init(4e4+1);
        for(int i=0; i<n; i++){
            // perform union of the stones, treating the row of each stone and col of each stone
            // as two members upon which union is to be performed
            int r = stones[i][0], c = stones[i][1];
            int c_ = c + 1e4 + 1;
            unionByRank(r, c_);
        }
        unordered_set<int> uniqueParents;
        for(int i=0; i<n; i++){
            int p1 = findParent(stones[i][0]), p2 = findParent(stones[i][1] + 1e4 + 1);
            uniqueParents.insert(p1);
            uniqueParents.insert(p2);
        }
        int components = uniqueParents.size();
        return n - components;
    }
};