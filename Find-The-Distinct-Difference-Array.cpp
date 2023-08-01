// Leetcode 2670

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        unordered_set<int> hash;
        for(int i=0; i<n; i++){
            hash.insert(nums[i]);
            prefix[i] = hash.size();
        }
        hash.clear();
        for(int i=n-1; i>=0; i--){
            hash.insert(nums[i]);
            suffix[i] = hash.size();
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = prefix[i] - ((i+1) < n ? suffix[i+1] : 0);
        }
        return ans;
    }
};