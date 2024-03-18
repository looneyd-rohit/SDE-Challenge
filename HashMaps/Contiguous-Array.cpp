// Leetcode 525

// Approach: using hashmap (khandani wala approach)
class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
      nums[i] == 0 ? nums[i] = -1 : 0;
    unordered_map<int, int> hash;
    int sum = 0;
    hash[0] = -1;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      int req = sum - 0;
      if (hash.find(req) != hash.end()) {
        maxi = max(maxi, i - hash[req]);
      } else if (hash.find(sum) == hash.end()) {
        hash[sum] = i;
      }
    }
    return maxi;
  }
};