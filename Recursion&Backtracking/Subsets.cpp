// Leetcode 78

// Approach: recursion + take, not take logic
class Solution {
public:
    void solve(int index, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(index == n){
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[index]);
        solve(index+1, n, nums, temp, ans);
        temp.pop_back();

        // not take
        solve(index+1, n, nums, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, n, nums, temp, ans);
        return ans;
    }
};