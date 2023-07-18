// Leetcode 1984

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int mini = 1e9;
        for(int i=0; i+k-1<n; i++){
            int j = i+k-1;
            int diff = nums[j] - nums[i];
            mini = min(mini, diff);
        }
        return mini;
    }
};