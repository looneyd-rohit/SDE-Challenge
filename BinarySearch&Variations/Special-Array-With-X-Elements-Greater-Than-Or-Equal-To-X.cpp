// Leetcode 1608

// Approach: binary search
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int low = 0, high = 1000;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int ub = lower_bound(begin(nums), end(nums), mid) - begin(nums);
            int cnt = n - ub;
            if(mid == cnt){
                return mid;
            }else if(mid < cnt){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
};