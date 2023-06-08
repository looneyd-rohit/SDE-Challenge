class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // using visited approach
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[abs(nums[i]) - 1] < 0){
                // if already visited push in array
                ans.push_back(abs(nums[i]));
            }else{
                // marking visited
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return ans;
    }
};