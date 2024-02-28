// Leetcode 1887

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = 0;
        for(int i=n-1; i>0; i--){
            if(nums[i-1]!=nums[i]){
                // all nos. b/w [i...n-1] needs to be converted to nums[i-1]
                ans += (n-i);
            }
        }
        return ans;
    }
};