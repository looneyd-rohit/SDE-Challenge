// Leetcode 2779
// [IMP]: Hard to get that binary search will be applicable

class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int len){
        int n = nums.size();
        for(int i=0; i+len-1<n; i++){
            int j = i + len - 1;
            if(nums[i]+k >= nums[j]-k){
                return true;
            }
        }
        return false;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int low = 1, high = n;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int len = mid;
            bool flag = isPossible(nums, k, len);
            if(flag){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};