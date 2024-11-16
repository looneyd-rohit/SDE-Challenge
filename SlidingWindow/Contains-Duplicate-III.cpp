// Leetcode 220

// Approach: sliding window + multisets
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        int i = 0, j = 0;
        multiset<int> mst;  // ordered set will keep items sorted within the given window
        int mini = 1e9;
        while(j < n){
            mst.insert(nums[j]);

            if((j-i) <= indexDiff){
                auto it = mst.upper_bound(nums[j]);
                if(it!=mst.end()) mini = min(mini, abs(nums[j] - *it));
                it--;
                if(it!=mst.begin()) mini = min(mini, abs(nums[j] - *prev(it)));
                j++;
            }else{
                while(i<=j && (j-i)>indexDiff){
                    mst.erase(mst.find(nums[i]));
                    i++;
                }
                auto it = mst.upper_bound(nums[j]);
                if(it!=mst.end()) mini = min(mini, abs(nums[j] - *it));
                it--;
                if(it!=mst.begin()) mini = min(mini, abs(nums[j] - *prev(it)));
                j++;
            }
        }
        return (mini <= valueDiff);
    }
};