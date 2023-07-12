// Leetcode 2327
// DP with counting pattern, recursive message passing

class Solution {
public:
    const int M = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // in the i-th day if k people knows the secret, then in (i+delay)-th day
        // k more people will know the secret
        // this will continue till the i-th day person forgets
        vector<int> dp(1e4, 0);
        dp[1] = 1;    // at day=1, 1 person knows
        
        // finding out what all new persons came to know about the secret on the upcoming days
        for(int day=1; day<=n; day++){
            for(int next=day+delay; next<day+forget; next++){
                // on the next-day all persons on day-day who know the secret share to them
                dp[next] += dp[day];
                dp[next] %= M;
            }
        }
        
        int ans = 0;
        // n-forget+1 --> the minimum day, where all people currently knowing the secret don't forget
        // on reaching n-th day
        for(int i=max(1, n-forget+1); i<=n; i++){
            ans += dp[i];
            ans %= M;
        }
        return ans;
    }
};