// Leetcode 3095

// Approach: brute force
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = -1;
        for(int i=0; i<n; i++){
            int x = 0;
            for(int j=i; j<n; j++){
                x = x | (nums[j]);
                if(x >= k){
                    if(mini == -1) mini = j-i+1;
                    else mini = min(mini, j-i+1);
                }
            }
        }
        return mini;
    }
};