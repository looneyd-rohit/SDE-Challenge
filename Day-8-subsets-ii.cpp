class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        // base case
        if(index >= nums.size()){
            return ;
        }

        for(int i=index; i<nums.size(); i++){
            // skipping duplicates
            if(i > index && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            ans.push_back(temp);
            solve(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // using duplicate skipping technique
        // sort the array first
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        ans.push_back(temp);
        solve(0, nums, temp, ans);
        return ans;
    }
};