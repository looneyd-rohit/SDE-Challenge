// Leetcode 2967

// Approach: generate all the closest palindromes of median and take the min
// cost sum
class Solution {
public:
  vector<long long> nearestPalindromicNumbers(string n) {
    int len = n.length();
    vector<long long> palindromes;
    // just greater -> 1...00000...1 (edge case)
    palindromes.push_back((1LL * pow(10, len)) + 1);
    // just smaller -> 999...999 (edge case)
    palindromes.push_back((1LL * pow(10, len - 1)) - 1);
    // numbers formed with first half
    long long root = stoll(n.substr(0, (len + 1) >> 1));
    for (int dx = -1; dx <= 1; dx++) {
      string modified_root = to_string(root + dx);
      if (len & 1) {
        // odd
        string new_str = modified_root +
                         string(rbegin(modified_root) + 1, rend(modified_root));
        palindromes.push_back(stoll(new_str));
      } else {
        // even
        string new_str =
            modified_root + string(rbegin(modified_root), rend(modified_root));
        palindromes.push_back(stoll(new_str));
      }
    }
    return palindromes;
  }
  long long minimumCost(vector<int> &nums) {
    // to minimize cost when we need to make all elements equal to some
    // particular element -> our focus shifts towards median
    // but here median may or may not be palindromic, so we need to get
    // the closest palindrome of the median of nums
    int n = nums.size();
    sort(begin(nums), end(nums));
    int median =
        (n & 1) ? nums[n >> 1] : (nums[(n - 1) >> 1] + nums[n >> 1]) >> 1;
    vector<long long> palindromes =
        nearestPalindromicNumbers(to_string(median));
    long long mini_cost = LONG_LONG_MAX;
    for (auto &p : palindromes) {
      long long sum = 0;
      for (auto &num : nums) {
        sum += abs(num - p);
      }
      mini_cost = min(mini_cost, sum);
    }
    return mini_cost;
  }
};