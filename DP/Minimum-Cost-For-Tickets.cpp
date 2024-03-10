// Leetcode 983

// Approach 1: dp + binary search upper bound
class Solution {
public:
  int dp[1001];
  int solve(int index, vector<int> &days, vector<int> &costs) {
    if (index >= days.size())
      return 0;

    if (dp[index] != -1)
      return dp[index];

    int one_day_pass = costs[0];
    int ub_one =
        upper_bound(begin(days) + index, end(days), days[index]) - begin(days);
    one_day_pass += solve(ub_one, days, costs);

    int seven_day_pass = costs[1];
    int ub_seven =
        upper_bound(begin(days) + index, end(days), days[index] + 6) -
        begin(days);
    seven_day_pass += solve(ub_seven, days, costs);

    int thirty_day_pass = costs[2];
    int ub_thirty =
        upper_bound(begin(days) + index, end(days), days[index] + 29) -
        begin(days);
    thirty_day_pass += solve(ub_thirty, days, costs);

    return dp[index] = min({one_day_pass, seven_day_pass, thirty_day_pass});
  }
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int n = days.size();
    sort(begin(days), end(days));
    memset(dp, -1, sizeof(dp));
    return solve(0, days, costs);
  }
};

// Approach 2: bottom up + unordered set
class Solution {
public:
  int dp[1001];
  int solve(int index, vector<int> &days, vector<int> &costs) {
    if (index >= days.size())
      return 0;

    if (dp[index] != -1)
      return dp[index];

    int one_day_pass = costs[0];
    int ub_one =
        upper_bound(begin(days) + index, end(days), days[index]) - begin(days);
    one_day_pass += solve(ub_one, days, costs);

    int seven_day_pass = costs[1];
    int ub_seven =
        upper_bound(begin(days) + index, end(days), days[index] + 6) -
        begin(days);
    seven_day_pass += solve(ub_seven, days, costs);

    int thirty_day_pass = costs[2];
    int ub_thirty =
        upper_bound(begin(days) + index, end(days), days[index] + 29) -
        begin(days);
    thirty_day_pass += solve(ub_thirty, days, costs);

    return dp[index] = min({one_day_pass, seven_day_pass, thirty_day_pass});
  }
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int n = days.size();
    // sort(begin(days), end(days));
    memset(dp, -1, sizeof(dp));
    // return solve(0, days, costs);

    // bottom up
    unordered_set<int> ust(begin(days), end(days));
    int last_day = days.back();
    vector<int> dp2(last_day + 1);
    for (int day = 1; day <= last_day; day++) {
      if (ust.count(day) == false) {
        dp2[day] = dp2[day - 1];
        continue;
      }
      int one_day_pass = costs[0] + dp2[max(day - 1, 0)];
      int seven_day_pass = costs[1] + dp2[max(day - 7, 0)];
      int thirty_day_pass = costs[2] + dp2[max(day - 30, 0)];
      dp2[day] = min({one_day_pass, seven_day_pass, thirty_day_pass});
    }
    return dp2[last_day];
  }
};