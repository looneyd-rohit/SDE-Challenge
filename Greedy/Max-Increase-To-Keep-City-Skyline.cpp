// Leetcode 807

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        // skyline from top/bottom
        vector<int> top(n, 0);
        // skyline from left/right
        vector<int> right(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                top[i] = max(top[i], grid[j][i]);
                right[i] = max(right[i], grid[i][j]);
            }
        }
        int maxiIncrease = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                maxiIncrease += min(top[j], right[i]) - grid[i][j];
            }
        }
        return maxiIncrease;
    }
};