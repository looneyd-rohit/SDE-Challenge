// Leetcode 491

// [IMP] Approach: avoiding duplicates traversing by recursion + set
class Solution {
public:
  void solve(int index, int n, vector<int> &nums, vector<int> &temp,
             vector<vector<int>> &ans) {
    if (temp.size() >= 2)
      ans.push_back(temp);

    // take - not take won't work as duplicates may be present
    // use for loop framework
    unordered_set<int> ust; // set defined in each recursion call
                            // to avoid taking the same element again
                            // in the same recursion
                            // [ if array was sorted we could have used
                            // if arr[i]==arr[i-1] then continue; ]
                            // used in combination sum ii
    for (int i = index; i < n; i++) {
      if (!ust.count(nums[i])) {
        if (temp.empty() || temp.back() <= nums[i]) {
          temp.push_back(nums[i]);
          solve(i + 1, n, nums, temp, ans);
          temp.pop_back();
        }
        ust.insert(nums[i]);
      }
    }
  }
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> ans;
    solve(0, n, nums, temp, ans);
    return ans;
  }
};