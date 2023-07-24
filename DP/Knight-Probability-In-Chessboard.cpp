// Leetcode 688

class Solution {
public:
    double dp[26][26][101];
    vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    double solve(int i, int j, int n, int k){
        // base case
        if(i < 0 || j < 0 || i >= n || j >= n) return 0;
        // knight still in board and moves exhausted
        if(k == 0) return 1;
        
        // dp check
        if(dp[i][j][k]!=0.0) return dp[i][j][k];
        
        double probability = 0.0;
        for(auto& m: moves){
            int di = m.first, dj = m.second;
            int new_i = i + di, new_j = j + dj;
            probability += solve(new_i, new_j, n, k-1);
        }
        return dp[i][j][k] = probability / 8;
    }
    double knightProbability(int n, int k, int row, int column) {
        // at every step we have 8 options to move, so lets assume solve() returns
        // probability of moving on a particular direction, then we will sum up probability
        // of all 8 directions and divide by 8 [general intuition] --> [favourable / total]
        // base case --> when k = 0, probability of staying in board = a1
        memset(dp, 0.0, sizeof(dp));
        return solve(row, column, n, k);
    }
};