// Leetcode 128

// Approach 1: sorting
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    sort(begin(nums), end(nums));
    int max_count = 1, count = 1, prev = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] == prev) {
        // do nothing
      } else if (nums[i] == prev + 1) {
        // increase the count
        prev = nums[i];
        count++;
        max_count = max(max_count, count);
      } else {
        // start new sequence
        prev = nums[i];
        count = 1;
      }
    }
    return max_count;
  }
};

// Approach 2: hashing
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    unordered_set<int> st;
    for (auto &e : nums)
      st.insert(e);
    int max_count = 0;
    for (auto &e : st) {
      if (st.find(e - 1) ==
          st.end()) { // this is the first element of the sequence
        int x = e;
        int count = 1;
        max_count = max(max_count, count);
        while (st.find(x + 1) != st.end()) {
          x++;
          count++;
          max_count = max(max_count, count);
        }
      }
    }
    return max_count;
  }
};