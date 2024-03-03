// Leetcode 2864

class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int n = s.length();
    int freq_one = 0;
    for (auto &e : s)
      if (e == '1')
        freq_one++;
    int freq_zero = n - freq_one;
    freq_one--;
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (freq_one)
        ans.push_back('1'), freq_one--;
      else if (freq_zero)
        ans.push_back('0'), freq_zero--;
    }
    ans.push_back('1');
    return ans;
  }
};