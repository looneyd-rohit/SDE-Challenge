// Leetcode 2167

class Solution {
public:
    int dp[(int)2e5+1][3];
    int solve(int index, int stage, string& s){
        // base case
        if(index >= s.length()){
            return 0;
        }
        
        // dp check
        if(dp[index][stage]!=-1) return dp[index][stage];
        
        // form stages --> left deletion stage 0, mid deletion stage 1, right deletion stage 2
        int ans = 1e9;
        for(int curr=stage; curr<=2; curr++){
            if(curr == 0){
                // delete irrespective of 0 or 1
                ans = min(ans, 1 + solve(index+1, curr, s));
            }
            else if(curr == 1){
                // delete only if 1 not 0
                if(s[index] == '0'){
                    ans = min(ans, solve(index+1, curr, s));
                }else{
                    // delete 1 with 2 cost
                    ans = min(ans, 2 + solve(index+1, curr, s));
                }
            }
            else{
                // delete irrespective of 0 or 1
                ans = min(ans, 1 + solve(index+1, curr, s));
            }
        }
        return dp[index][stage] = ans;
    }
    int minimumTime(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};