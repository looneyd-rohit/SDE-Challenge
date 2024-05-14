// Leetcode 2441

// Approach: set based approach
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ust(begin(nums), end(nums));
        for(int i=-1000; i<=-1; i++){
            if(ust.find(i)!=ust.end()){
                if(ust.find(abs(i)) != ust.end()){
                    return abs(i);
                }
            }
        }
        return -1;
    }
};