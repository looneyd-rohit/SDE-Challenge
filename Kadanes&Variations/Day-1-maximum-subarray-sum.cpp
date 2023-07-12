// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;
//         int currSum = 0;
//         for(int i=0; i<n; i++){
//             currSum += nums[i];
//             maxi = max(maxi, currSum);
//             if(currSum < 0){
//                 currSum = 0;
//             }
//         }
//         return maxi;
//     }
// };

// Kadane's Problem
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's problem
        int n = nums.size();
        int maxOverall = -1e9, maxTillNow = -1e9;
        for(int i=0; i<n; i++){
            maxTillNow = max(nums[i], maxTillNow+nums[i]);
            
            maxOverall = max(maxOverall, maxTillNow);
            
            if(maxTillNow < 0) maxTillNow = 0;
        }
        return maxOverall;
    }
};