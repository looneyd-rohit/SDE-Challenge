// Leetcode 2366

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long last = nums.back();
        long long ans = 0;
        for(int i=n-2; i>=0; i--){
            long long parts = nums[i] / last;
            if(nums[i] % last != 0){
                parts++;
                last = nums[i] / parts;
            }
            ans += parts - 1;
        }
        return ans;
    }
};