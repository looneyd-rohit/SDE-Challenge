// Leetcode 2958

// Approach: khandani sliding window template
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int i = 0, j = 0;
        int maxi = 0;
        while(j < n){
            hash[nums[j]]++;

            if(hash[nums[j]] <= k){
                maxi = max(maxi, j-i+1);
                j++;
            }else{
                while(i<=j && hash[nums[j]]>k){
                    hash[nums[i]]--;
                    if(hash[nums[i]]==0) hash.erase(nums[i]);
                    i++;
                }
                maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return maxi;
    }
};