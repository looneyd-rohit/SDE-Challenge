// Leetcode 179

// [IMP] Approach: sorting with custom comparator
class Solution {
public:
  static bool cmp(const int &a, const int &b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
  }
  string largestNumber(vector<int> &nums) {
    int n = nums.size();
    sort(begin(nums), end(nums), cmp);
    string ans = "";
    for (auto &e : nums)
      ans += to_string(e);
    int i = 0;
    for (i = 0; i < n; i++)
      if (ans[i] != '0')
        break;
    return ans.substr(i) == "" ? "0" : ans.substr(i);
  }
};