// Leetcode 2940

// [IMP] Approach: segment trees (range sum) + binary search
class SGTree {
public:
  vector<int> segarr;
  SGTree(int n = 0) { this->segarr.resize(4 * n + 1, INT_MIN); }
  void build(int index, int low, int high, vector<int> &arr) {
    if (low == high) {
      this->segarr[index] = arr[low];
      return;
    }
    int mid = low + ((high - low) >> 1);
    build(2 * index + 1, low, mid, arr);
    build(2 * index + 2, mid + 1, high, arr);
    this->segarr[index] =
        max(this->segarr[2 * index + 1], this->segarr[2 * index + 2]);
  }
  void update(int index, int low, int high, int ind, int val) {
    if (low == high) {
      this->segarr[index] = val;
      return;
    }
    int mid = low + ((high - low) >> 1);
    if (ind <= mid) {
      update(2 * index + 1, low, mid, ind, val);
    } else {
      update(2 * index + 2, mid + 1, high, ind, val);
    }
    this->segarr[index] =
        max(this->segarr[2 * index + 1], this->segarr[2 * index + 2]);
  }
  auto query(int index, int low, int high, int l, int r) {
    // no overlap
    if (r < low || high < l)
      return INT_MIN;

    // full overlap
    if (l <= low && high <= r)
      return this->segarr[index];

    // partial overlap
    int mid = low + ((high - low) >> 1);
    auto left = query(2 * index + 1, low, mid, l, r);
    auto right = query(2 * index + 2, mid + 1, high, l, r);
    return max(left, right);
  }
};
class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int> &heights,
                                      vector<vector<int>> &queries) {
    int n = heights.size();
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
      ump[heights[i]] = i;
    SGTree *sgtree = new SGTree(n);
    sgtree->build(0, 0, n - 1, heights);
    int q = queries.size();
    vector<int> ans;
    // segment tree can only give maximum in a given range
    // but we need to find the maximum leaning to the left
    // so we need to do multiple segment queries by shrinking
    // the array size bringing it to the left
    for (int i = 0; i < q; i++) {
      int a = queries[i][0], b = queries[i][1];
      if (a > b)
        swap(a, b);

      if (a == b || (a < b && heights[a] < heights[b])) {
        ans.push_back(b);
      } else {
        int max_height = max(heights[a], heights[b]);
        int low = b, high = n - 1;
        while (low <= high) {
          int mid = low + ((high - low) >> 1);
          int max_possible = sgtree->query(0, 0, n - 1, low, mid);
          if (max_possible > max_height) {
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        }
        if (low != n) {
          ans.push_back(low);
        } else {
          ans.push_back(-1);
        }
      }
    }
    return ans;
  }
};