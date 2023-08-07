// Leetcode 1579
// [IMP]: DSU nice application
class DSU{
    public:
    vector<int> parent, rank, size;
    DSU(int n = 0){
        parent.resize(n+1); rank.resize(n+1, 0), size.resize(n+1, 1);
        size[0] = 0;
        parent[0] = -1;
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    bool unionByRank(int u, int v){
        u = findParent(u);
        v = findParent(v);
        // false --> no merging was done
        if(u == v) return false;
        if(rank[u] == rank[v]){
            parent[v] = u;
            rank[u]++;
            // size[u] += size[v];
        }else if(rank[u] > rank[v]){
            parent[v] = u;
            // size[u] += size[v];
        }else{
            parent[u] = v;
            // size[v] += size[u];
        }
        // true --> merging was done
        return true;
    }
    bool unionBySize(int u, int v){
        u = findParent(u);
        v = findParent(v);
        // false --> no merging was done
        if(u == v) return false;
        if(size[u] == size[v]){
            parent[v] = u;
            size[u] += size[v];
        }else if(size[u] > size[v]){
            parent[v] = u;
            size[u] += size[v];
        }else{
            parent[u] = v;
            size[v] += size[u];
        }
        // true --> merging was done
        return true;
    }
};
class Solution {
public:
    int solve(int n, vector<vector<int>>& edges){
        int e = edges.size();
        // init DSU
        DSU dsu1(n), dsu2(n);
        int alice = 0, bob = 0, notNeeded = 0;
        for(int i=0; i<e; i++){
            int t = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(t == 3){
                bool flag1 = dsu1.unionByRank(u, v);
                bool flag2 = dsu2.unionByRank(u, v);
                if(flag1 || flag2){
                    // if alice takes type 3 edge then bob also has to take
                    // since it helps both of them traverse
                    // because if alice takes it, then bob can also traverse so
                    // he will take it rather than taking others
                    alice++; bob++;
                }else if(!flag1 && !flag2){
                    notNeeded++;
                }
            }else if(t == 1){
                bool flag = dsu1.unionByRank(u, v);
                if(flag){
                    // merging was done
                    alice++;
                }else{
                    notNeeded++;
                }
            }else{
                bool flag = dsu2.unionByRank(u, v);
                if(flag){
                    // merging was done
                    bob++;
                }else{
                    notNeeded++;
                }
            }
        }
        if(n-1==alice && n-1==bob){
            // if whole graph can be traversed
            return notNeeded;
        }
        return -1;
    }
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] > b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        sort(begin(edges), end(edges), cmp);
        return solve(n, edges);
    }
};