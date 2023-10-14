// Leetcode 238

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        long long pdt = 1;
        for(auto& e: nums){
            if(e==0) zeroCount++;
            else pdt *= e;
        }
        vector<int> ans(n, 0);
        if(zeroCount==0){
            for(int i=0; i<n; i++) ans[i] = pdt / nums[i];
        }else if(zeroCount==1){
            for(int i=0; i<n; i++){
                if(nums[i]!=0) ans[i] = 0;
                else ans[i] = pdt;
            }
        }
        return ans;
    }
};