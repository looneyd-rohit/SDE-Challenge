// Leetcode 135

// Approach 1: using two traversals left + right
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> counts(n, 1);
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        counts[i] = max(counts[i], counts[i - 1] + 1);
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        counts[i] = max(counts[i], counts[i + 1] + 1);
      }
    }
    int candies = 0;
    for (int i = 0; i < n; i++) {
      candies += counts[i];
    }
    return candies;
  }
};

// Approach 2: optimized O(1) space
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    int candies = n;
    for (int i = 1; i < n;) {
      // skip similar
      while (i < n && ratings[i] == ratings[i - 1])
        i++;
      int peak = 0, dip = 0;
      while (i < n && ratings[i] > ratings[i - 1]) {
        // upward peak
        peak++;
        candies += peak;
        i++;
      }
      while (i < n && ratings[i] < ratings[i - 1]) {
        // downward dip
        dip++;
        candies += dip;
        i++;
      }
      candies -= min(peak, dip);
    }
    return candies;
  }
};