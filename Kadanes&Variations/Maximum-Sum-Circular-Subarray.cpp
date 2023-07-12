// Leetcode 918

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // kadane's variation
        int n = nums.size();
        int total = 0;
        int maxOverall = -1e9, maxTillNow = -1e9;
        int minOverall = 1e9, minTillNow = 1e9;
        for(int i=0; i<n; i++){
            maxTillNow = max(nums[i], maxTillNow+nums[i]);
            
            maxOverall = max(maxOverall, maxTillNow);
            
            minTillNow = min(nums[i], minTillNow+nums[i]);
            
            minOverall = min(minOverall, minTillNow);
            
            total += nums[i];
        }
        return maxOverall > 0 ? max(maxOverall, total-minOverall) : maxOverall;
    }
};