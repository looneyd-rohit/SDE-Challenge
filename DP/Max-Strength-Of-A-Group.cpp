// Leetcode 2708

class Solution {
public:
    long long solve(int index, int n, vector<int>& nums, long long product, bool notZero){
        // base case
        if(index >= n){
            if(notZero == false){
                // empty subset
                long long m = LONG_LONG_MIN;
                for(auto& e: nums) if(e!=0) m = max(m, 1LL*e);
                return m;
            }
            return product;
        }
        
        // pick
        long long pick = solve(index+1, n, nums, product * 1LL * nums[index], true);
        
        // not pick
        long long notPick = solve(index+1, n, nums, product, notZero);
        
        return max(pick, notPick);
    }
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n, nums, 1, false);
    }
};