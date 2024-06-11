// Leetcode 1296

// Approach: store frequencies in a map and then iterate for all the consecutive elements and decrement counts
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        map<int, int> mp;
        for(auto& e: nums) mp[e]++;
        for(auto& e: mp){
            int first = e.first;
            int f = e.second;
            if(f==0) continue;
            mp[first] = 0;
            for(int num=first+1; num<(first+k); num++){
                if(mp[num]<f) return false;
                mp[num] -= f;
            }
        }
        return true;
    }
};