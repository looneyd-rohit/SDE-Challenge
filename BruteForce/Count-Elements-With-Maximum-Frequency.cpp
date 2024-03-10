// Leetcode 3005

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> freq(101, 0);
    int max_freq = 0, cnt_max_freq = 0;
    for (auto &e : nums) {
      freq[e]++;
      if (freq[e] > max_freq) {
        max_freq = freq[e];
        cnt_max_freq = 1;
      } else if (freq[e] == max_freq) {
        cnt_max_freq++;
      }
    }
    return (max_freq * cnt_max_freq);
  }
};