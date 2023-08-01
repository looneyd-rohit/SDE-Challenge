// Leetcode 2684

class Solution {
public:
    int dp[1001][1001];
    vector<pair<int, int>> moves = {{1, 1}, {0, 1}, {-1, 1}};
    bool checkBounds(int x, int y, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }
    int traverse(int x, int y, vector<vector<int>>& grid){
        // base case
        if(y == grid[0].size()-1) return 0;

        // dp check
        if(dp[x][y]!=-1) return dp[x][y];

        int maxi = 0;
        for(auto& move: moves){
            int dx = move.first, dy = move.second;
            int new_x = x + dx, new_y = y + dy;
            if(checkBounds(new_x, new_y, grid)){
                if(grid[new_x][new_y] > grid[x][y]){
                    maxi = max(maxi, 1 + traverse(new_x, new_y, grid));
                }
            }
        }
        return dp[x][y] = maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;
        // memoization:
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<m; i++){
            maxi = max(maxi, traverse(i, 0, grid));
        }
        return maxi;
    }
};