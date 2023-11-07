// Leetcode 2920
// IMP: Some unique way to check tree + DP concept
class Solution {
public:
    int dp[(int)1e5+1][14+1];
    // note 1: since max coin value is 1e4 so max div can go upto 14, above it
    // value / div will turn out to be 0 no matter what, and it will contribute negative
    // scores
    // note 2: we observe that since this structure is a tree, we don't need 3-D DP
    // because for each particular node and each particular div, parent is the same
    int solve(int node, int par, int div, int k, unordered_map<int, vector<int>>& adj, vector<int>& coins){
        // first optimization
        if(div > 14) return 0;

        // dp check
        if(dp[node][div]!=-1) return dp[node][div];

        // first way
        int first = ((coins[node] >> div) - k);
        // second way
        int second = ((coins[node] >> div) >> 1);
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i]==par) continue;
            first += solve(adj[node][i], node, div, k, adj, coins);
            second += solve(adj[node][i], node, div + 1, k, adj, coins);
        }
        return dp[node][div] = max({first, second});
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        // construct the adjacency graph/tree
        int n = coins.size();
        unordered_map<int, vector<int>> adj;
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, 0, k, adj, coins);
    }
};