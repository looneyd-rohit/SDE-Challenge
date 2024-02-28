// Leetcode 3047

class Solution {
public:
  long long largestSquareArea(vector<vector<int>> &bottomLeft,
                              vector<vector<int>> &topRight) {
    int n = bottomLeft.size();
    unsigned long area = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        // first rectangle
        long long blx1 = bottomLeft[i][0], bly1 = bottomLeft[i][1];
        long long trx1 = topRight[i][0], try1 = topRight[i][1];

        // second rectangle
        long long blx2 = bottomLeft[j][0], bly2 = bottomLeft[j][1];
        long long trx2 = topRight[j][0], try2 = topRight[j][1];

        long long blx_ = max(blx1, blx2), bly_ = max(bly1, bly2);
        long long trx_ = min(trx1, trx2), try_ = min(try1, try2);

        if (trx_ < blx_ || try_ < bly_)
          continue;

        long long x_ = abs(blx_ - trx_), y_ = abs(bly_ - try_);

        long long side = min(x_, y_);

        long long curr_area = pow(side, 2);

        if (curr_area > area)
          area = curr_area;
      }
    }
    return area;
  }
};