// Leetcode 1615

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        for(auto& road: roads){
            int u = road[0], v = road[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int c1 = adj[i].size(), c2 = adj[j].size();
                if(adj[i].count(j)){
                    cnt = max(cnt, c1 + c2 - 1);
                }else{
                    cnt = max(cnt,  c1 + c2);
                }
            }
        }
        return cnt;
    }
};