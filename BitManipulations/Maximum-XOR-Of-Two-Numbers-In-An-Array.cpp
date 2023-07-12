// Leetcode 421
// [IMP]: legit super question on bit manipulations, legendary
// excellent

class Solution {
public:
    int solve(vector<int>& nums, int target, int ans){
        unordered_set<int> hash;
        for(auto& num: nums){
            int setBits = num & target;
            int remainingRequired = setBits ^ target;
            if(hash.count(remainingRequired)){
                // target can be achieved
                return target;
            }
            hash.insert(setBits);
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        // logic: we have to maximize the xor, so in order to maximize we need more and more
        // set bits in th 0 - 31 position, also the set bits should be more towards the msb
        // of the resulting number, now we find pairs iterating for every i-th bit and looking for
        // if the i-th bit can be set or not. Also, while checking for the next i-th bit, preserve
        // the current i-th bit in the number we are looking for
        int ans = 0;
        for(int i=31; i>=0; i--){
            // start from msb since we are needed to maximize
            ans = solve(nums, ans | (1<<i), ans);
        }
        return ans;
    }
};