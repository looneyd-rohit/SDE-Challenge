// Leetcode 282

// Approach: HARD backtracking problem
class Solution {
public:
  vector<string> ans;
  void solve(int index, long long val, long long prev, char prev_op,
             string expression, string &num, int target) {
    if (index == num.length()) {
      if (target == val)
        ans.push_back(expression);
      return;
    }
    for (int j = index; j < num.length(); j++) {
      string temp = num.substr(index, j - index + 1);
      long long k = stoi(temp);
      if (to_string(k).size() != temp.size())
        continue;

      solve(j + 1, val + k, k, '+', expression + "+" + temp, num, target);
      solve(j + 1, val - k, k, '-', expression + "-" + temp, num, target);
      solve(j + 1,
            (prev_op == '-'
                 ? (val + prev) - k * prev
                 : (prev_op == '+' ? (val - prev) + k * prev : k * prev)),
            k * prev, prev_op, expression + "*" + temp, num, target);
    }
  }
  vector<string> addOperators(string num, int target) {
    int n = num.length();
    if (n == 0)
      return ans;
    for (int i = 0; i < n; i++) {
      string temp = num.substr(0, i + 1);
      long long k = stoll(temp);
      if (to_string(k).size() != temp.size())
        continue;
      solve(i + 1, k, k, '#', temp, num, target);
    }
    return ans;
  }
};