// Leetcode 813
// 0/1 Knapsack Pattern

class Solution {
public:
    double dp[101][101][101];
    double solve(int index, int prevInd, int k, vector<int>& nums, int n){
        // base case
        if(index >= n){
            if(k == 0) return 0;
            return -1e9;
        }
        
        if(k <= 0) return -1e9;
        
        // dp check
        if(dp[index][prevInd+1][k]!=0.0) return dp[index][prevInd+1][k];
        
        // place the partition after the current index
        double place = (nums[index] - (prevInd >= 0 ? nums[prevInd] : 0)) * 1.0 / (index-prevInd) + solve(index+1, index, k-1, nums, n);
        
        // don't place the partition after the current index
        double dontPlace = 0.0 + solve(index+1, prevInd, k, nums, n);
        
        return dp[index][prevInd+1][k] = max(place, dontPlace);
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        // it's better if we calculate prefix sums
        for(int i=1; i<n; i++) nums[i] += nums[i-1];
        // memoization:
        memset(dp, 0.0, sizeof(dp));
        return solve(0, -1, k, nums, n);
    }
};