// Leetcode 3075

class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    int n = happiness.size();
    long long total = 0;
    sort(begin(happiness), end(happiness));
    int diff = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (happiness[i] >= diff)
        total += happiness[i] - diff;
      diff++;
      if (diff == k)
        break;
    }
    return total;
  }
};