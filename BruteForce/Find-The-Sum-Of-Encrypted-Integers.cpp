// Leetcode 3079

class Solution {
public:
  int sumOfEncryptedInt(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      string str = to_string(nums[i]);
      int maxi = 0;
      for (auto &e : str) {
        maxi = max(maxi, e - '0');
      }
      for (int i = 0; i < str.length(); i++) {
        str[i] = (char)(maxi + '0');
      }
      int num = stoi(str);
      sum += num;
    }
    return sum;
  }
};