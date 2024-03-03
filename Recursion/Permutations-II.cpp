// Leetcode 47

// Approach 1: using hashmaps
class Solution {
public:
  void solve(unordered_map<int, int> &umap, int n, vector<int> &temp,
             vector<vector<int>> &ans) {
    // base case
    if (temp.size() == n) {
      ans.push_back(temp);
      return;
    }

    for (auto &pr : umap) {
      int e = pr.first, freq = pr.second;
      if (freq > 0) {
        umap[e]--;
        temp.push_back(e);
        solve(umap, n, temp, ans);
        temp.pop_back();
        umap[e]++;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> umap;
    for (auto &e : nums)
      umap[e]++;
    vector<int> temp;
    vector<vector<int>> ans;
    solve(umap, n, temp, ans);
    return ans;
  }
};

// Approach 2: using swap method + sets
class Solution {
public:
  void solve(int index, int n, vector<int> &nums, vector<vector<int>> &ans) {
    // base case
    if (index == n) {
      ans.push_back(nums);
      return;
    }
    unordered_set<int> ust;
    for (int i = index; i < n; i++) {
      if (ust.count(nums[i]))
        continue;
      swap(nums[i], nums[index]);
      solve(index + 1, n, nums, ans);
      swap(nums[i], nums[index]);
      ust.insert(nums[i]);
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    vector<vector<int>> ans;
    solve(0, n, nums, ans);
    return ans;
  }
};