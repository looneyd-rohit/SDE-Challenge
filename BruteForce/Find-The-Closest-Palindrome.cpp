// Leetcode 564

// Approach: brute forcing all possibilities + edge cases
class Solution {
public:
  string nearestPalindromic(string n) {
    int len = n.length();
    unordered_set<long long> ust;
    // just greater -> 1...00000...1 (edge case)
    ust.insert((1LL * pow(10, len)) + 1);
    // just smaller -> 999...999 (edge case)
    ust.insert((1LL * pow(10, len - 1)) - 1);
    // numbers formed with first half
    long long root = stoll(n.substr(0, (len + 1) >> 1));
    for (int dx = -1; dx <= 1; dx++) {
      string modified_root = to_string(root + dx);
      if (len & 1) {
        // odd
        string new_str = modified_root +
                         string(rbegin(modified_root) + 1, rend(modified_root));
        ust.insert(stoll(new_str));
      } else {
        // even
        string new_str =
            modified_root + string(rbegin(modified_root), rend(modified_root));
        ust.insert(stoll(new_str));
      }
    }
    // now take the one having least difference among all and also minimum
    // among all having same least differences
    ust.erase(stoll(n));
    long long mini_val = LONG_LONG_MAX, mini_diff = LONG_LONG_MAX;
    for (auto &num : ust) {
      long long diff = abs(num - stoll(n));
      if (diff < mini_diff) {
        mini_diff = diff;
        mini_val = num;
      } else if (diff == mini_diff) {
        mini_val = min(mini_val, num);
      }
    }
    return to_string(mini_val);
  }
};