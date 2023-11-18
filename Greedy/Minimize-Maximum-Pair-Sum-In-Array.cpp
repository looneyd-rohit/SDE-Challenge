// Leetcode 1877

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int maxi = 1;
        for(int i=0; i<n/2; i++){
            int sum = nums[i] + nums[n-i-1];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};