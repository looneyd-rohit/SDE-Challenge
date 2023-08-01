// Leetcode 77

class Solution {
public:
    void solve(int index, int n, int k, vector<int>& temp, vector<vector<int>>& ans){
        // base case
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<=n; i++){
            temp.push_back(i);
            solve(i+1, n, k, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1, n, k, temp, ans);
        return ans;
    }
};