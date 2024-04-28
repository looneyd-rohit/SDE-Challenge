// Leetcode 2547

// Approach 1: simple recursion + dp + precomputation
class Solution {
public:
    int dp[1001];
    int trimmed_dp[1001][1001];
    int solve(int index, int k, int n, vector<int>& nums){
        if(index == n) return 0;
        
        if(dp[index]!=-1) return dp[index];

        // partition the array
        unordered_map<int, int> ump;
        int cnt1 = 0, cnt2 = 0;
        int ans = INT_MAX;
        for(int j=index; j<n; j++){
            int e = nums[j];
            ump[e]++;
            if(ump[e]>=2) cnt1++;
            if(ump[e]==2) cnt2++;
            ans = min(ans, k + cnt1 + cnt2 + solve(j+1, k, n, nums));
        }
        return dp[index] = ans;
    }
    int solve2(int index, int k, int n, vector<int>& nums){
        if(index == n) return 0;
        
        if(dp[index]!=-1) return dp[index];

        // partition the array
        int ans = INT_MAX;
        for(int j=index; j<n; j++){
            ans = min(ans, k + trimmed_dp[index][j] + solve2(j+1, k, n, nums));
        }
        return dp[index] = ans;
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        memset(trimmed_dp, 0, sizeof(trimmed_dp));
        // precomputing every trimmed cost for each subarray
        for(int i=0; i<n; i++){
            unordered_map<int, int> ump;
            int cnt1 = 0, cnt2 = 0;
            for(int j=i; j<n; j++){
                int e = nums[j];
                ump[e]++;
                if(ump[e]>=2) cnt1++;
                if(ump[e]==2) cnt2++;
                trimmed_dp[i][j] = cnt1+cnt2;
            }
        }
        return solve2(0, k, n, nums);
    }
};