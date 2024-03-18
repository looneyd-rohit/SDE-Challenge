// Leetcode 791

// Approach 1: store in hashmap convert character to number
class Solution {
public:
  string customSortString(string order, string s) {
    int n = order.size();
    unordered_map<char, int> ump;
    for (int i = 0; i < n; i++)
      ump[order[i]] = i;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (ump.find(ch) == ump.end()) {
        ump[ch] = n++;
        order.push_back(ch);
      }
    }
    int m = s.size();
    vector<int> s_to_number(m, 0);
    for (int i = 0; i < m; i++) {
      s_to_number[i] = ump[s[i]];
    }
    sort(begin(s_to_number), end(s_to_number));
    string ans = "";
    for (int i = 0; i < m; i++) {
      int num = s_to_number[i];
      ans.push_back(order[num]);
    }
    return ans;
  }
};
