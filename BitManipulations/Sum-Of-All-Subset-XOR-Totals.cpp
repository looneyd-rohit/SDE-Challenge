// Leetcode 1863

// Approach: classic forming all subsets approach
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<(1<<n); i++){
            int x = 0;
            for(int bit=0; bit<n; bit++){
                if(i & (1<<bit)){
                    x = x ^ nums[bit];
                }
            }
            sum += x;
        }
        return sum;
    }
};