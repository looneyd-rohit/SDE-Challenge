// Leetcode 223

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int xlow = max(ax1, bx1), ylow = max(ay1, by1);
    int xhigh = min(ax2, bx2), yhigh = min(ay2, by2);
    int x = max(xhigh - xlow, 0), y = max(yhigh - ylow, 0);
    int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
    int common = x * y;
    return (area1 + area2 - common);
  }
};