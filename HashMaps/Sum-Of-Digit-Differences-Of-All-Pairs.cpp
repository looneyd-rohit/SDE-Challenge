// Leetcode 3153

// Approach: distint digit pair combination
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        int maxi = to_string(nums[0]).size();
        for(int i=0; i<maxi; i++){
            map<int, int> mp;
            for(auto& num: nums){
                string str = to_string(num);
                mp[str[i]-'0']++;
            }
            for(auto& e: mp){
                int s = e.second;
                total += (s * 1LL * (nums.size() - s));
            }
        }
        return total/2;
    }
};