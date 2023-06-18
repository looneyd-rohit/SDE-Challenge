class Solution {
public:
    int solve(int i, int j, vector<pair<int, char>>& groups, vector<vector<int>>& dp){
        // base case
        if(i > j) return 0;

        // dp check
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1e9;
        // remove the i-th group along with extras --> then try for remaining groups from i+1 till j
        // here we don't need extras variable as it has nothing to do with calculating cost
        ans = min(ans, 1 + solve(i+1, j, groups, dp));

        // don't remove the i-th group --> instead try to merge it with i+2 / i+4 / i+6 .... groups
        for(int group=i+2; group<=j; group+=1){
            // in first call extra = 0, since extra is count of items similar to i-th group, and i+1-th
            // group is different so we pass 0
            if(groups[group].second == groups[i].second){
                ans = min(ans, solve(i+1, group-1, groups, dp) + solve(group, j, groups, dp));
            }
        }
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        // similar to remove boxes, we need to find the minimum steps in which we can make the string
        // empty, provided grouping of similar characters are allowed
        int n = s.length();
        vector<pair<int, char>> groups;
        char prev = s[0]; int cnt = 1;
        for(int i=1; i<n; i++){
            if(prev == s[i]){
                cnt++;
            }else{
                groups.push_back({cnt, prev});
                prev = s[i];
                cnt = 1;
            }
        }
        groups.push_back({cnt, prev});
        int m = groups.size();
        // memoization:
        // vector<vector<int>> dp(m, vector<int>(m, -1));
        // return solve(0, m-1, groups, dp);

        // tabulation:
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        for(int i=m-1; i>=0; i--){
            for(int j=i; j<=m-1; j++){
                int ans = 1e9;
                // remove the i-th group along with extras --> then try for remaining groups from i+1 till j
                // here we don't need extras variable as it has nothing to do with calculating cost
                ans = min(ans, 1 + dp[i+1][j]);

                // don't remove the i-th group --> instead try to merge it with i+2 / i+4 / i+6 .... groups
                for(int group=i+2; group<=j; group+=1){
                    // in first call extra = 0, since extra is count of items similar to i-th group, and i+1-th
                    // group is different so we pass 0
                    if(groups[group].second == groups[i].second){
                        ans = min(ans, dp[i+1][group-1] + dp[group][j]);
                    }
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][m-1];
    }
};