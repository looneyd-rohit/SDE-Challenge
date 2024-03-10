// Leetcode 935

class Solution {
public:
    const int M = 1e9+7;
    vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1,2}, {1, -2}, {-1, -2}};
    bool checkBounds(int x, int y, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(x>=0 && y>=0 && x<m && y<n){
            if(grid[x][y]!=-1){
                return true;
            }
        }
        return false;
    }
    int dp[4][5][5001];
    int solve(int x, int y, int n, vector<vector<int>>& grid){
        // base case
        if(n == 0) return 1;

        // dp check
        if(dp[x][y][n]!=-1) return dp[x][y][n];

        int ans = 0;
        for(auto& move: moves){
            int dx = move.first, dy = move.second;
            int new_x = x + dx, new_y = y + dy;
            if(checkBounds(new_x, new_y, grid)){
                ans += solve(new_x, new_y, n-1, grid) % M;
                ans %= M;
            }
        }
        return dp[x][y][n] = ans;
    }
    int knightDialer(int n) {
        vector<vector<int>> grid = {{1,2,3}, {4,5,6}, {7,8,9}, {-1, 0, -1}};
        int m = grid.size(), n_ = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n_; j++){
                if(grid[i][j]!=-1){
                    ans += solve(i, j, n-1, grid) % M;
                    ans %= M;
                }
            }
        }
        return ans;
    }
};