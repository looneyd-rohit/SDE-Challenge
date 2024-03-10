// Leetcode 46

// Approach 1: Using Hashmap
class Solution {
public:
    void solve(unordered_set<int>& uset, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        // base case
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            if(!uset.count(nums[i])){
                uset.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(uset, n, nums, temp, ans);
                temp.pop_back();
                uset.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset;
        vector<int> temp;
        vector<vector<int>> ans;
        solve(uset, n, nums, temp, ans);
        return ans;
    }
};

// Approach 2: Using Swap technique
class Solution {
public:
    void solve(int index, int n, vector<int>& nums, vector<vector<int>>& ans){
        // base case
        if(index >= n){
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<n; i++){
            swap(nums[index], nums[i]);

            solve(index+1, n, nums, ans);

            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(0, n, nums, ans);
        return ans;
    }
};

// Approach 3: Using Bitmasking (unique elements)
class Solution {
public:
    void solve(int mask, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        // base case
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            if(mask & (1 << i)){
                // already taken
            }else{
                temp.push_back(nums[i]);
                solve(mask | (1<<i), n, nums, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, n, nums, temp, ans);
        return ans;
    }
};