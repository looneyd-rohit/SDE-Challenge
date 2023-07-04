// Leetcode 137

// bit manipulation approach:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(32, 0);
        for(int i=0; i<n; i++){
            int e = nums[i];
            for(int j=0; j<32; j++){
                if((e & (1<<j))){
                    bits[j] += 1;
                }
                bits[j] %= 3;
            }
        }
        int ans = 0;
        for(int j=0; j<32; j++){
            ans = ans + (bits[j] * (1<<j));
        }
        return ans;
    }
};