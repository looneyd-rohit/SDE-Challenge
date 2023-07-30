// Leetcode 2799
// Sliding Window Count Pattern
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinct;
        for(auto& e: nums) distinct.insert(e);
        int d = distinct.size() - 1;
        int i=0, j=0;
        unordered_map<int, int> hash;
        int sz = 0;
        int cnt = 0;
        // find the count of all subarrays with 1 to d-1 distinct elements
        while(j < n){
            int e = nums[j];
            hash[e]++;
            if(hash[e]==1) sz++;
            
            if(sz <= d){
                // expand not yet reached
                cnt += j-i+1;
                j++;
            }else{
                // reached
                while(sz > d){
                    hash[nums[i]]--;
                    if(hash[nums[i]]==0){
                        // remove this element
                        sz--;
                    }
                    i++;
                }
                cnt += j-i+1;
                j++;
            }
        }
        return n*(n+1)/2 - cnt;
    }
};