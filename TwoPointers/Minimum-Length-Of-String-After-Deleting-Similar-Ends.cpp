// Leetcode 1750

class Solution {
public:
  int minimumLength(string s) {
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return (j - i + 1);
      }

      int temp_i = i, temp_j = j;
      while (temp_i < n - 1 && s[temp_i] == s[temp_i + 1])
        temp_i++;
      while (temp_j > 0 && s[temp_j] == s[temp_j - 1])
        temp_j--;

      if (temp_i >= temp_j)
        return 0;

      i = temp_i + 1, j = temp_j - 1;
    }
    return (j - i + 1);
  }
};