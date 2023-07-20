// Leetcode 1799
// [IMP]: DP + Bitmasking
class Solution {
public:
    int dp[10][(1<<14)];
    int solve(int id, int mask, int n, vector<int>& nums){
        // base case
        if(mask == 0) return 0;    // all numbers used up
        
        // dp check
        if(dp[id][mask]!=-1) return dp[id][mask];
        
        // mask --> tells how many numbers are currently available
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((mask&(1<<i)) && (mask&(1<<j))){
                    // both exists, compute gcd and go for next pair
                    ans = max(ans, id * (gcd(nums[i], nums[j])) + solve(id+1, (mask ^ (1<<i)) ^ (1<<j), n, nums));
                }
            }
        }
        return dp[id][mask] = ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = (1 << n) - 1;
        memset(dp, -1, sizeof(dp));
        return solve(1, mask, n, nums);
    }
};