// Leetcode 1000
// [IMP]: DP MCM Merge Pattern
class Solution {
public:
    int dp[31][31];
    int solve(int i, int j, vector<int>& stones, int k){
        // base case
        if(i>=j) return 0;    // if one stone remaining or all stones exhausted then 0 cost
        
        // dp check
        if(dp[i][j]!=-1) return dp[i][j];
        
        // merge stone b/w i and j by dividing them then
        // then merging [i...p] [p+1...j] individually
        // then finally [i...j] needs to merged to add their prefix sum
        // typical MCM pattern
        int ans = 1e9;
        for(int p=i; p<j; p+=k-1){
            ans = min(ans, solve(i,p, stones, k) + solve(p+1, j, stones, k));
        }
        if(((j-i) % (k-1)) == 0){
            ans += stones[j] - ((i >= 1) ? stones[i-1] : 0);
        }
        return dp[i][j] = ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if(((n-1)%(k-1))!=0) return -1;
        for(int i=1; i<n; i++) stones[i] += stones[i-1];
        // memoization:
        // memset(dp, -1, sizeof(dp));
        // return solve(0, n-1, stones, k);
        
        // tabulation:
        memset(dp, 1e9, sizeof(dp));
        for(int i=0; i<31; i++) for(int j=0; j<31; j++) if(i>=j) dp[i][j] = 0;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<=n-1; j++){
                // merge stone b/w i and j by dividing them then
                // then merging [i...p] [p+1...j] individually
                // then finally [i...j] needs to merged to add their prefix sum
                // typical MCM pattern
                int ans = 1e9;
                for(int p=i; p<j; p+=k-1){
                    ans = min(ans, dp[i][p] + dp[p+1][j]);
                }
                if(((j-i) % (k-1)) == 0){
                    ans += stones[j] - ((i >= 1) ? stones[i-1] : 0);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};