// Leetcode 926

// Approach 1: top down dp
class Solution {
public:
  int dp[(int)1e5 + 1][2];
  int solve(int index, bool flag, string &s) {
    if (index >= s.length())
      return 0;

    if (dp[index][flag] != -1)
      return dp[index][flag];

    if (flag) {
      // flag == true --> all characters are zero before
      if (s[index] == '0') {
        int a = solve(index + 1, flag, s);      // don't change
        int b = 1 + solve(index + 1, false, s); // change
        return dp[index][flag] = min(a, b);
      } else {
        int a = solve(index + 1, false, s);    // don't change
        int b = 1 + solve(index + 1, flag, s); // change
        return dp[index][flag] = min(a, b);
      }
    } else {
      // flag == false --> 1 has occured before
      // so make everything 1 now
      return dp[index][flag] = (s[index] == '0') + solve(index + 1, flag, s);
    }
  }
  int minFlipsMonoIncr(string s) {
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    return solve(0, true, s);
  }
};

// Approach 2: smart and unique approach
class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int n = s.length();
    int count_of_ones = 0;
    int flips = 0;
    // assume string s[0...i] is monotonically increasing
    // by doing 'flips' no. of flippings then process the current
    // index
    for (int i = 0; i < n; i++) {
      count_of_ones += s[i] == '1';
      if (s[i] == '0') {
        flips = min(1 + flips, count_of_ones);
      }
    }
    return flips;
  }
};