// Leetcode 1489
// [IMP]: MST IMPORTANT PATTERN
class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n=0){
        parent.resize(n+1); rank.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        u = findParent(u); v = findParent(v);
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
    int kruskalMST(int n, vector<vector<int>>& edges, int skip, int add){
        int sum = 0;
        if(add!=-1){
            unionByRank(edges[add][0], edges[add][1]);
            sum += edges[add][2];
        }
        // cout<<"after add"<<endl;
        for(int i=0; i<edges.size(); i++){
            if(i == skip) continue;
            int u = edges[i][0], v = edges[i][1];
            int wt = edges[i][2];
            if(findParent(u)!=findParent(v)){
                unionByRank(u, v);
                sum += wt;
            }
        }
        // check if mst forms or not
        for(int i=0; i<n; i++){
            if(findParent(i)!=findParent(0)){
                return INT_MAX;
            }
        }
        return sum;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> modifiedEdges;
        for(int i=0; i<edges.size(); i++){
            modifiedEdges.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }
        sort(begin(modifiedEdges), end(modifiedEdges), [](auto a, auto b){
            return a[2] < b[2];
        });
        DSU normal_dsu(n);
        int normalMST = normal_dsu.kruskalMST(n, modifiedEdges, -1, -1);
        vector<int> critical, pseudo_critical;
        for(int i=0; i<modifiedEdges.size(); i++){
            DSU skip_dsu(n), add_dsu(n);
            // skip
            int skipMST = skip_dsu.kruskalMST(n, modifiedEdges, i, -1);
            if(skipMST > normalMST){    // critical
                critical.push_back(modifiedEdges[i][3]);
                continue;
            }

            // add
            int addMST = add_dsu.kruskalMST(n, modifiedEdges, -1, i);
            if(addMST == normalMST){    // critical
                pseudo_critical.push_back(modifiedEdges[i][3]);
            }
        }
        return {critical, pseudo_critical};
    }
};