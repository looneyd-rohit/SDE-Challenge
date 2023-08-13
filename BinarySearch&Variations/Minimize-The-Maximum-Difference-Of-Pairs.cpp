// Leetcode 2616

class Solution {
public:
    bool isPossible(vector<int>& nums, int p, int diff){
        int n = nums.size();
        int count = 0, mini = 1e9;
        for(int i=1; i<n; i++){
            int d = nums[i] - nums[i-1];
            if(d <= diff){
                count++;
                // skip i, once more to not select this pair
                i++;
            }
        }
        return (count >= p);
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int low = 0, high = 1e9;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int diff = mid;
            bool flag = isPossible(nums, p, diff);
            if(flag){
                // reduce diff
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};