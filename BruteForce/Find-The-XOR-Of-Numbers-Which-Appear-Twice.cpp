// Leetcode 3158

// Approach: brute force
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        int x = 0;
        for(auto& e: nums) ump[e]++;
        for(auto& e: ump) if(e.second==2) x = x ^ e.first;
        return x;
    }
};