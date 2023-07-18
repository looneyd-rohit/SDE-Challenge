// Leetcode 2588

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // nice: everytime we pick two indices and find if they have a common 1 bit at a
        // position, and then we remove that bit and continue this process for all the
        // elements within the subarray of that particular index
        // now to simplify this, we can say that a given subarray is beautiful if we can
        // pick a pair having k-th bit set and delete k-th bit, k ranging from 0 to 31
        // hence after all the deletions, every element will be 0
        // so, we can say it seems like xor of two elements
        // problem boils down to subarray xor equals 0
        int n = nums.size();
        vector<int> prefixXor(n, nums[0]);
        for(int i=1; i<n; i++) prefixXor[i] = prefixXor[i-1] ^ nums[i];
        unordered_map<int, int> hash;
        long long count = 0;
        for(int i=0; i<n; i++){
            int xorr = prefixXor[i];
            if(xorr == 0) count++;
            int req = prefixXor[i];
            if(hash.find(req)!=hash.end()) count+=hash[req];
            hash[xorr]++;
        }
        return count;
    }
};