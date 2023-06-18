// Recursion is better here, than the tabulation --> more intuitive actually
class Solution {
public:
    int solve(int i, int j, int extra, vector<pair<int, int>>& groups, vector<vector<vector<int>>>& dp){
        // base case
        if(i > j) return 0;

        // dp check
        if(dp[i][j][extra]!=-1) return dp[i][j][extra];

        int ans = -1e9;
        // remove the i-th group along with extras --> then try for remaining groups from i+1 till j
        ans = max(ans, (groups[i].first+extra)*(groups[i].first+extra) + solve(i+1, j, 0, groups, dp));

        // don't remove the i-th group --> instead try to merge it with i+2 / i+4 / i+6 .... groups
        for(int group=i+2; group<=j; group+=1){
            // in first call extra = 0, since extra is count of items similar to i-th group, and i+1-th
            // group is different so we pass 0
            if(groups[group].second == groups[i].second){
                ans = max(ans, solve(i+1, group-1, 0, groups, dp) + solve(group, j, extra+groups[i].first, groups, dp));
            }
        }
        return dp[i][j][extra] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        // convert into groups for easier traversal b/w groups
        // explanation: watch --> https://www.youtube.com/watch?v=NINZAQFW_AE
        // i can't explain this better than him...
        int n = boxes.size();
        vector<pair<int, int>> groups;
        int prev = boxes[0];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(prev == boxes[i]){
                cnt++;
            }else{
                groups.push_back({cnt, prev});
                prev = boxes[i];
                cnt = 1;
            }
        }
        groups.push_back({cnt, prev});
        int m = groups.size();
        // memoization:
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(m, vector<int>(n, -1)));
        // return solve(0, m-1, 0, groups, dp);

        // tabulation:
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(m+1, vector<int>(n+100, 0)));

        for(int i=m-1; i>=0; i--){
            for(int j=i; j<=m-1; j++){
                for(int extra=n; extra>=0; extra--){
                    int ans = -1e9;
                    // remove the i-th group along with extras --> then try for remaining groups from i+1 till j
                    ans = max(ans, (groups[i].first+extra)*(groups[i].first+extra) + dp[i+1][j][0]);

                    // don't remove the i-th group --> instead try to merge it with i+2 / i+4 / i+6 .... groups
                    for(int group=i+2; group<=j; group+=1){
                        // in first call extra = 0, since extra is count of items similar to i-th group, and i+1-th
                        // group is different so we pass 0
                        if(groups[group].second == groups[i].second){
                            ans = max(ans, dp[i+1][group-1][0] + dp[group][j][extra+groups[i].first]);
                        }
                    }
                    dp[i][j][extra] = ans;
                }
            }
        }
        return dp[0][m-1][0];
    }
};