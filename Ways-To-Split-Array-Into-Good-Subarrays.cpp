// Leetcode 2750
class Solution {
public:
    const int M = 1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        // the extreme left and extreme right zeros have no significance, since they have to be attached to
        // their most nearest 1's
        // the 0's in between can be either attached to left 1 or right 1
        int firstOne = 0, lastOne = n-1;
        while(firstOne<n && nums[firstOne]==0) firstOne++;
        while(lastOne>=0 && nums[lastOne]==0) lastOne--;
        if(firstOne > lastOne) return 0;
        long long ans = 1;
        int cnt = 0;
        // cout<<firstOne<<" "<<lastOne<<endl;
        firstOne++;
        while(firstOne <= lastOne){
            // count 0's in between
            if(nums[firstOne] == 0){
                cnt++;
                firstOne++;
            }else{
                ans = (ans * (cnt + 1)) % M;
                cnt = 0;
                firstOne++;
            }
        }
        return ans % M;
    }
};