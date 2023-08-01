// Leetcode 526

class Solution {
public:
    int dp[17][(int)(1<<16) + 2];
    int solve(int index, int mask, int n){
        // base case
        if(index > n) return 1;

        // dp check
        if(dp[index][mask]!=-1) return dp[index][mask];

        // get the next integer
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(mask & (1 << i)){
                // already taken
            }else{
                // check divisibility
                if(i % index == 0 || index % i == 0){
                    ans += solve(index+1, mask | (1<<i), n);
                }
            }
        }
        return dp[index][mask] = ans;
    }
    int countArrangement(int n) {
        // using bit masking
        // mask will give us the nos. currently used
        // take 1-based indexing for convenience
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n);
    }
};