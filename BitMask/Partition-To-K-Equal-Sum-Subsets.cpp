// Leetcode 698

// Approach 1: DP + Bitmasks
class Solution {
public:
    int dp[(int)(1<<16)+1][17];
    bool solve(int mask, int sum, int& n, int& sum_of_each, vector<int>& nums, int k){
        // base case
        if(mask == ((1<<n)-1)){
            return (k==0);
        }

        // dp check
        if(dp[mask][k]!=-1) return dp[mask][k];

        // try to take the next element such that it matches the sum_of_each
        bool ans = false;
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                // already taken
            }else{
                if(sum + nums[i] < sum_of_each){
                    ans = ans | solve(mask | (1<<i), sum+nums[i], n, sum_of_each, nums, k);
                }else if(sum + nums[i] == sum_of_each){
                    ans = ans | solve(mask | (1<<i), 0, n, sum_of_each, nums, k-1);
                }
            }
        }
        return dp[mask][k] = ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for(auto& e: nums) total += e;
        if(total % k != 0) return false;
        int sum_of_each = total / k;
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, sum_of_each, nums, k);
    }
};

// Approach 2: