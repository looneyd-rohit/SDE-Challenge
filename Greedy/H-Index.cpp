// Leetcode 274

// Approach 1: sorting + lower_bound
class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    sort(begin(citations), end(citations));
    int max_h = 0;
    for (auto &e : citations)
      cout << e << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) {
      int lb =
          lower_bound(begin(citations), end(citations), i) - begin(citations);
      int diff = n - lb;
      if (diff < i)
        continue;
      max_h = max(max_h, i);
    }
    return max_h;
  }
};

// Approach 2: count sort
class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    vector<int> freq(n + 1, 0);
    for (auto &e : citations)
      freq[min(e, n)]++;
    int cnt = 0;
    for (int i = n; i >= 0; i--) {
      // sum of citations above i
      // i represents the number of papers
      // cnt represents the probable h index
      cnt += freq[i];
      if (cnt >= i)
        return i;
    }
    return 0;
  }
};