// Leetcode 220

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    int n = nums.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
      v.push_back({nums[i], i});
    sort(begin(v), end(v));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(v[j].first - v[i].first) <= valueDiff) {
          if (abs(v[j].second - v[i].second) <= indexDiff) {
            return true;
          }
        } else {
          break;
        }
      }
    }
    return false;
  }
};