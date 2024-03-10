// Leetcode 3074

class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    int n = apple.size(), m = capacity.size();
    int total_apples = 0;
    for (auto &e : apple)
      total_apples += e;
    sort(begin(capacity), end(capacity));
    int total_cap = 0;
    for (int i = m - 1; i >= 0; i--) {
      total_cap += capacity[i];
      if (total_cap >= total_apples) {
        return m - i;
      }
    }
    return -1;
  }
};