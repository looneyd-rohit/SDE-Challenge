// Leetcode 1219

// Approach: brute force recursion
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0;

        int t = grid[i][j];

        grid[i][j] = 0;

        int right = solve(i, j+1, m, n, grid);
        int left = solve(i, j-1, m, n, grid);
        int up = solve(i-1, j, m, n, grid);
        int down = solve(i+1, j, m, n, grid);

        grid[i][j] = t;

        return t + max({right, left, up, down});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                maxi = max(maxi, solve(i, j, m, n, grid));
            }
        }
        return maxi;
    }
};