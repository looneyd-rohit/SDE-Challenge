// Leetcode 1986
// [IMP]: DP + Bitmasks
class Solution {
public:
    int dp[(1<<14)][211];
    int solve(int mask, int n, vector<int>& tasks, int elapsed, int sessionTime){
        // base case
        if(mask == 0) return 0;    // no tasks remaining
        
        // dp check
        if(dp[mask][elapsed]!=-1) return dp[mask][elapsed];
        
        // maks --> gives current available tasks
        int ans = 1e9;
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                // task not yet done
                int m = elapsed / sessionTime;
                int rem = elapsed % sessionTime;
                if(rem == 0 || rem + tasks[i] > sessionTime){
                    ans = min(ans, 1 + solve(mask ^ (1<<i), n, tasks, m*sessionTime + tasks[i], sessionTime));
                }else{
                    ans = min(ans, solve(mask ^ (1<<i), n, tasks, elapsed + tasks[i], sessionTime));
                }
            }
        }
        return dp[mask][elapsed] = ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int mask = (1 << n) - 1;
        memset(dp, -1, sizeof(dp));
        return solve(mask, n, tasks, 0, sessionTime);
    }
};
