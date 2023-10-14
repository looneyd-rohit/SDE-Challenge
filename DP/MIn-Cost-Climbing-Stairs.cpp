// Leetcode 746

class Solution {
public:
    int dp[(int)1001];
    int solve(int index, int n, vector<int>& cost){
        // base case
        if(index >= n){
            return 0;
        }

        // dp check
        if(dp[index]!=-1) return dp[index];

        int one = cost[index] + solve(index+1, n, cost);

        int two = cost[index] + solve(index+2, n, cost);

        return dp[index] = min({one, two});
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min({solve(0, n, cost), solve(1, n, cost)});
    }
};