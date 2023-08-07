// Leetcode 1697
// [IMP]: DSU + Sorting nice logic
class Solution {
public:
    vector<int> parent, rank;
    void init(int n){
        parent.resize(n+1, 0); rank.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
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
    static bool cmp(vector<int>& a, vector<int>& b){
        return a.back() < b.back();
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // DSU based question: go on adding those edges to the graph whose weights are strictly
        // less than the weight of the current query; also keep the queries sorted in ascending order
        // of weights, so that when a lower edge is already added, it does not need to be added
        // again, to reduce repeatitive work
        // store the edge pairs corresponding to a particular edge weight
        int e = edgeList.size(), q = queries.size();
        vector<vector<int>> sortedQ;
        for(int i=0; i<q; i++){
            sortedQ.push_back({i, queries[i][0], queries[i][1], queries[i][2]});
        }
        // sort the edges for seamless addition/union
        sort(begin(edgeList), end(edgeList), cmp);
        // sort the queries
        sort(begin(sortedQ), end(sortedQ), cmp);
        // init the DSU
        init(n);
        vector<bool> ans(q, false);

        int ind = 0;
        for(int i=0; i<q; i++){
            int queryInd = sortedQ[i][0], p_ = sortedQ[i][1], q_ = sortedQ[i][2], wt_ = sortedQ[i][3];

            // add the edges where edge wt < wt_
            while(ind < e && edgeList[ind][2] < wt_){
                int u_ = edgeList[ind][0], v_ = edgeList[ind][1];
                unionByRank(u_, v_);
                ind++;
            }

            if(findParent(p_) == findParent(q_)){
                ans[queryInd] = true;
            }
        }
        return ans;
    }
};