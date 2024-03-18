// Leetcode 1639

// [IMP] Approach: forming a map which stores the frequency of characters at
// every index
class Solution {
public:
  const int M = 1e9 + 7;
  long long dp[1005][1005];
  long long solve(int index, int column, string &target,
                  vector<unordered_map<char, int>> &freq_map) {
    // base cases
    if (index >= target.size())
      return 1;
    if (column >= freq_map.size())
      return 0;

    if (dp[index][column] != -1)
      return dp[index][column];

    // take
    long long take = 0;
    if (freq_map[column][target[index]] > 0) {
      take = (freq_map[column][target[index]] *
              (solve(index + 1, column + 1, target, freq_map) % M)) %
             M;
    }

    // not take
    long long not_take = solve(index, column + 1, target, freq_map) % M;

    return dp[index][column] = (take + not_take) % M;
  }
  int numWays(vector<string> &words, string target) {
    int n = words.size(), m = words[0].size();
    vector<unordered_map<char, int>> freq_map(m);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        freq_map[j][words[i][j]]++;
      }
    }
    // memset(dp, -1, sizeof(dp));
    // return solve(0, 0, target, freq_map);

    // bottom up dp:
    // state: dp[i][j] --> no. of ways of forming target[0...i] taking
    // word[0...j] i and j represents length
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // forming empty string from empty word -> 1 way
    // for(int len=0; len<=target.size(); len++) dp[len][0] = 1;
    for (int k = 0; k <= m; k++)
      dp[0][k] = 1;
    // forming empty string from non empty word -> 1 ways
    // forming non empty string from empty word -> 0 ways
    // (len, k) -> depends on (len, k-1) {not taking kth} and (len-1, k-1)
    // {taking kth}
    for (int len = 1; len <= target.size(); len++) {
      for (int k = 1; k <= m; k++) {
        dp[len][k] += dp[len][k - 1] % M; // not take
        dp[len][k] %= M;
        dp[len][k] +=
            (dp[len - 1][k - 1] * 1LL * freq_map[k - 1][target[len - 1]]) %
            M; // take
        dp[len][k] %= M;
      }
    }
    return dp[target.size()][m];
  }
};