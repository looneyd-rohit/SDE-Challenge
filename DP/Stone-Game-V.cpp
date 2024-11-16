// Leetcode 1563
// [IMP]: Standard DP
class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector<int>& prefix){
        // base case
        if(i == j) return 0;
        
        // dp check
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = -1e9;
        for(int k=i; k<j; k++){
            // left part --> [i...k]
            int leftScore = prefix[k] - (i > 0 ? prefix[i-1] : 0);
            
            // right part --> [k+1...j]
            int rightScore = prefix[j] - prefix[k];
            
            if(leftScore < rightScore){
                ans = max(ans, leftScore + solve(i, k, prefix));
            }else if(rightScore < leftScore){
                ans = max(ans, rightScore + solve(k+1, j, prefix));
            }else{
                ans = max(ans, max(leftScore + solve(i, k, prefix), rightScore + solve(k+1, j, prefix)));
            }
            
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n, stoneValue[0]);
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + stoneValue[i];
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, prefix);
    }
};