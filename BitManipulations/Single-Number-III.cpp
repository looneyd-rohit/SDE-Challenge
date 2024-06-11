// Leetcode 260

// Approach: xor + bit manipulations
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long x = 0;
        for(auto& e: nums) x = x ^ e;
        int last_set_bit = x & (-x);
        int a = 0, b = 0;
        for(auto& e: nums){
            if(e & last_set_bit){
                a = a ^ e;
            }else{
                b = b ^ e;
            }
        }
        return {a, b};
    }
};