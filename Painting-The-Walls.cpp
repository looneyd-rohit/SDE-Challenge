// Leetcode 2742
// Knapsack (0/1) DP pattern
class Solution {
public:
    int solve(int index, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        // base case
        if(index == -1){
            // tried out all painters
            if(walls == 0) return 0;
            return 1e9;
        }

        // dp check
        if(dp[index][walls]!=-1) return dp[index][walls];
        
        // take the current paid painter to paint walls
        int new_walls = walls - 1 - time[index] >= 0 ? walls - 1 - time[index] : 0;
        int take = cost[index] + solve(index-1, new_walls, cost, time, dp);
        
        // don't take the current paid painter to paint the walls
        int notTake = 0 + solve(index-1, walls, cost, time, dp);
        
        return dp[index][walls] = min(take, notTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        // memoization:
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int ans = solve(n-1, n, cost, time, dp);
        return ans;
    }
};