// Leetcode 2226

class Solution {
public:
  bool isPossible(vector<int> &candies, long long k, unsigned long long mid) {
    int n = candies.size();
    // check if count of piles >= mid is >= k
    // then only it will be possible
    unsigned long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (candies[i] >= mid) {
        cnt += (1LL * candies[i]) / mid;
        if (cnt >= k)
          return true;
      }
    }
    return false;
  }
  int maximumCandies(vector<int> &candies, long long k) {
    // looks like binary search let's try
    int n = candies.size();
    unsigned long long low = 1, high = 0;
    for (auto &e : candies)
      high += e;
    while (low <= high) {
      unsigned long long mid = low + ((high - low) >> 1);
      if (isPossible(candies, k, mid)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return high;
  }
};