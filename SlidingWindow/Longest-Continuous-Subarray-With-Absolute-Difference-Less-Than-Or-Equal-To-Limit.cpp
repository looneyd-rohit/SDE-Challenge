// Leetcode 1438

// Approach: sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> mst;
        int i=0, j=0;
        int len = 1;
        while(j < n){
            mst.insert(nums[j]);

            int diff = *mst.rbegin() - *mst.begin();
            if(diff <= limit){
                len = max(len, j-i+1);
                j++;
            }else{
                while(diff > limit && i <= j){
                    mst.erase(mst.find(nums[i]));
                    i++;
                    if(!mst.empty()) diff = *mst.rbegin() - *mst.begin();
                }
                len = max(len, j-i+1);
                j++;
            }
        }
        return len;
    }
};