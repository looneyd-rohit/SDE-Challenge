// Leetcode 2640

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conver(n, 0);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            conver[i] = nums[i] + maxi;
            if(i > 0) conver[i] += conver[i-1];
        }
        return conver;
    }
};