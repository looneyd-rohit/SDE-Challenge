// Leetcode 2369

class Solution {
public:
    int dp[(int)1e5+1];
    bool solve(int index, int n, vector<int>& nums){
        // base case
        if(index == n) return true;
        if(n-index <= 1) return false;

        // dp check
        if(dp[index]!=-1) return dp[index];

        bool ans = false;
        for(int i=index; i<n; i++){
            int sz = i-index+1;
            if(sz == 2){
                // check for both equal
                if(nums[i]==nums[index]) ans = ans | solve(i+1, n, nums);
            }else if(sz == 3){
                // check for all equal
                if(nums[i]==nums[index] && nums[index]==nums[index+1]) ans = ans | solve(i+1, n, nums);
                // check for increasing
                else if(nums[index]+1==nums[index+1] && nums[index+1]+1==nums[index+2]) ans = ans | solve(i+1, n, nums);
            }else if(sz > 3){
                break;
            }
            // above all if nothing is satisfied, form all possible partitions
            if(ans) break;
        }
        return dp[index] = ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums);
    }
};