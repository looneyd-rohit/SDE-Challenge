// Leetcode 2466
// Maths Number Counting + DP

// Approach 1: Counting all numbers of length 0 to n
// Do this for both high and (low-1) and subtract them
class Solution {
public:
    const int M = 1e9+7;
    int solve(int len, bool prev, int zero, int one, vector<vector<int>>& dp){
        // base case
        if(len == 0) return 1;
        if(len < 0) return 0;
        
        // dp check
        if(dp[len][prev]!=-1) return dp[len][prev] % M;
        
        // started taking zero or one
        if(prev){
            int a = solve(len-zero, prev, zero, one, dp);
            int b = solve(len-one, prev, zero, one, dp);
            return dp[len][prev] = (1LL*a+b) % M;
        }else{
            // not yet started taking zero or one
            int a = solve(len-zero, true, zero, one, dp);
            int b = solve(len-one, true, zero, one, dp);
            int c = solve(len-1, false, zero, one, dp);
            return dp[len][prev] = ((1LL*a+b) % M + 1LL*c) % M;
        }
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // calculating all numbers of all lengths possible to form upto
        // a limit length
        // memoization:
        vector<vector<int>> dp(1e5+1, vector<int>(2, -1));
        int lb = solve(low-1, 0, zero, one, dp);
        int ub = solve(high, 0, zero, one, dp);
        // cout<<lb<<" to "<<ub<<endl;
        return ((ub - lb) % M + M) % M;
    }
};


// Approach 2:
// Count all possible of a particular length n
class Solution {
public:
    const int M = 1e9+7;
    int solve(int len, int zero, int one, vector<int>& dp){
        // base case
        if(len == 0) return 1;
        if(len < 0) return 0;
        
        // dp check
        if(dp[len]!=-1) return dp[len] % M;
        
        int a = solve(len-zero, zero, one, dp);
        int b = solve(len-one, zero, one, dp);
        return dp[len] = (1LL*a+b) % M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // calculating all numbers of a given length
        // memoization:
        vector<int> dp(1e5+1, -1);
        long long ans = 0;
        for(int i=low; i<=high; i++){
            ans += solve(i, zero, one, dp);
            ans %= M;
        }
        return ans;
    }
};