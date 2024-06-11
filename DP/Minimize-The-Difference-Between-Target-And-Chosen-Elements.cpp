// Leetcode 1981

// Approach 1: dp = recursion + memoization
class Solution {
public:
    int dp[71][4901];
    int solve(int row, int sum, int m, int n, vector<vector<int>>& mat, int target){
        if(row == m) return abs(target - sum);
        if(dp[row][sum]!=-1) return dp[row][sum];
        int ans = 1e9;
        for(int col=0; col<n; col++){
            ans = min(ans, solve(row+1, sum+mat[row][col], m, n, mat, target));
            if(ans == 0) break;
        }
        return dp[row][sum] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n, mat, target);
    }
};

// Approach 2: using bitsets
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        // using bitsets approach
        int m = mat.size(), n = mat[0].size();
        const int sz = 4901;
        bitset<sz> dp;
        dp[0] = 1;
        for(auto& row: mat){
            bitset<sz> new_dp;
            for(auto& e: row){
                new_dp = new_dp | (dp << e);
            }
            dp = new_dp;
        }
        int mini_diff = 1e9;
        for(int val=4900; val>=0; val--){
            if(dp[val]){
                mini_diff = min(mini_diff, abs(target - val));
                if(mini_diff == 0) break;
            }
        }
        return mini_diff;
    }
};