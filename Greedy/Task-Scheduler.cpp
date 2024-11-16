// Leetcode 621

// Approach [IMP]: Greedy type approach, form schedules
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> freq(26, 0);
    int maxi = 0, cnt = 0;
    for (auto &e : tasks) {
      freq[e - 'A']++;
      if (maxi < freq[e - 'A']) {
        maxi = freq[e - 'A'];
        cnt = 1;
      } else if (maxi == freq[e - 'A']) {
        cnt++;
      }
    }
    // edge case when n is not large enough
    return max((int)tasks.size(), (maxi + (maxi - 1) * n) + (cnt - 1));
  }
};