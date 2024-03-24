// Leetcode 452

// Approach: khandani interval overlap wala approach
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    int n = points.size();
    sort(begin(points), end(points));
    int count = 1;
    int start = points[0][0], end = points[0][1];
    for (int i = 1; i < n; i++) {
      if (points[i][0] <= end && points[i][1] >= start) {
        // overlap occurs
        start = max(start, points[i][0]);
        end = min(end, points[i][1]);
      } else {
        // no overlap
        count++;
        start = points[i][0];
        end = points[i][1];
      }
    }
    return count;
  }
};