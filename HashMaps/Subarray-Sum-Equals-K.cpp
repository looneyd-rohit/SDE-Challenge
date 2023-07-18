// Leetcode 560

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // array consists of both negative and positive elements, so one side decision cannot
        // be made, hence normal sliding window not applicable
        int n = nums.size();
        vector<int> prefixSum(n, nums[0]);
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        unordered_map<int, int> hash;
        int count = 0;
        for(int i=0; i<n; i++){
            int sum = prefixSum[i];
            if(sum == k) count++;
            
            int req = sum - k;
            
            if(hash.find(req)!=hash.end()){
                // exists
                count+=hash[req];
            }
            
            hash[sum]++;
        }
        return count;
    }
};