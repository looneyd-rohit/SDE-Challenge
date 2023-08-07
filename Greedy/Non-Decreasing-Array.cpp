// Leetcode 665
// [IMP]: Greedy Problem
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // the element will act as a pivot and both the left and right halves will
        // have to non-decreasing in order to achieve this
        int n = nums.size();
        int count = 0;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                if(count > 0) return false;

                if(i < 2 || nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }else{
                    nums[i] = nums[i-1];
                }
                count++;
            }
        }
        return true;
    }
};