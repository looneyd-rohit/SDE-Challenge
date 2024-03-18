// https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// [IMP] Approach: khandani rectangle wala approach c*c*r
class Solution {
public:
  int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    // khandani rectangle wala approach -> c * c * r + prefix sum
    for (int i = 0; i < R; i++) {
      for (int j = 1; j < C; j++) {
        M[i][j] += M[i][j - 1];
      }
    }
    // now apply kadane's on 2D matrix
    int max_overall = -1e9;
    for (int col = 0; col < C; col++) {
      for (int j = col; j < C; j++) {
        int max_till_now = 0;
        for (int i = 0; i < R; i++) {
          max_till_now =
              max(M[i][j] - (col > 0 ? M[i][col - 1] : 0),
                  max_till_now + M[i][j] - (col > 0 ? M[i][col - 1] : 0));
          max_overall = max(max_overall, max_till_now);
        }
      }
    }
    return max_overall;
  }
};