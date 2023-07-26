// Leetcode 2439

class Solution {
public:
    bool isPossible(vector<int>& nums, int val){
        int n = nums.size();
        vector<long long int> nums2(n);
        for(int i=0; i<n; i++) nums2[i] = 1LL*nums[i];
        for(int i=n-1; i>=1; i--){
            if(val < nums2[i]){
                long long int diff = nums2[i] - val;
                // nums2[i] -= diff;
                nums2[i-1] += diff;
            }
        }
        return nums2[0] <= val;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, mini = INT_MAX;
        for(int i=0; i<n; i++) maxi = max(maxi, nums[i]), mini = min(mini, nums[i]);
        // if(maxi == mini) return mini;
        int low = mini, high = maxi;
        int ans = maxi;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int val = mid;
            bool flag = isPossible(nums, val);
            if(flag){
                // possible to get maximum of val from nums
                // try for lower
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};