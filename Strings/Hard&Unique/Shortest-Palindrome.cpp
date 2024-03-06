// Leetcode 214

// Approach: using lps concept of kmp
class Solution {
public:
  void calculateLPS(string &pattern, vector<int> &lps) {
    int m = pattern.size();
    lps[0] = 0;
    int i = 1, length = 0;
    while (i < m) {
      if (pattern[i] == pattern[length]) {
        lps[i++] = ++length;
      } else {
        // move pointer to a lower lps
        if (length > 0)
          length = lps[length - 1];
        else
          i++;
      }
    }
  }
  string shortestPalindrome(string s) {
    int n = s.length();
    if (n <= 1)
      return s;
    // find the longest palindrome starting from 0-th index
    // then take the remaining string reverse it and add it in front
    // finding the longest palindrome -> by lps concept
    string my_str = s;
    reverse(begin(s), end(s));
    my_str = my_str + "$" + s;
    reverse(begin(s), end(s));
    vector<int> lps(2 * n + 1, 0);
    calculateLPS(my_str, lps);
    int maxi = lps.back(); // take the back element as pref match with suffix
    string extra = s.substr(maxi);
    reverse(begin(extra), end(extra));
    string ans = extra + s;
    return ans;
  }
};