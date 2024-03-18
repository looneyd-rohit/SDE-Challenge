// Leetcode 974

class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    int n = nums.size();
    int sum = 0, count = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      sum %= k;
      while (sum < 0)
        sum += k;
      sum %= k;

      int req = sum - 0;
      if (hash.find(req) != hash.end()) {
        count += hash[req];
      }
      hash[sum]++;
    }
    return count;
  }
};