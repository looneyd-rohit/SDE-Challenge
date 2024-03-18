// Leetcode 57

// Approach: using merge intervals logic
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();
    intervals.push_back(newInterval);
    sort(begin(intervals), end(intervals));
    vector<vector<int>> ans;
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i <= n; i++) {
      if (intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
      } else {
        ans.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }
    ans.push_back({start, end});
    return ans;
  }
};

// Approach 2: optimal merging only particular interval
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;
    while (i < intervals.size()) {
      if (intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
      } else if (intervals[i][0] > newInterval[1]) {
        ans.push_back(newInterval);
        while (i < intervals.size())
          ans.push_back(intervals[i++]);
        return ans;
      } else {
        // merge overlap
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
      }
    }
    ans.push_back(newInterval);
    return ans;
  }
};