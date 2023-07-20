// Leetcode 2163
// [IMP]: PrefixSum + SuffixSum + Heaps --> OP Concept

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size();
        int n = n3 / 3;
        // instead of removing try choosing, choosing n elements from front and n elements from back
        // for every index i of nums
        // then min diff = min(pref[i]-suff[i+1])
        vector<long long> prefix(n3, LONG_LONG_MAX), suffix(n3, LONG_LONG_MAX);
        long long presum = 0;
        priority_queue<int> maxheap;
        for(int i=0; i<n3; i++){
            presum += nums[i];
            maxheap.push(nums[i]);
            if(maxheap.size() > n){
                presum -= maxheap.top(); maxheap.pop();
            }
            if(maxheap.size() == n){
                prefix[i] = presum;
            }
        }
        long long suffsum = 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i=n3-1; i>=0; i--){
            suffsum += nums[i];
            minheap.push(nums[i]);
            if(minheap.size() > n){
                suffsum -= minheap.top(); minheap.pop();
            }
            if(minheap.size() == n){
                suffix[i] = suffsum;
            }
        }
        long long diff = LONG_LONG_MAX;
        for(int i=0; i<n3-1; i++){
            if(prefix[i]!=LONG_LONG_MAX && suffix[i+1]!=LONG_LONG_MAX)
                diff = min(diff, prefix[i]-suffix[i+1]);
        }
        return diff;
    }
};