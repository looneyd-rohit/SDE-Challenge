// Leetcode 2407

// [IMP] Approach: segment tree but array stores dp table
class SGTree {
public:
  vector<int> segarr;
  SGTree(int n = 0) { this->segarr.resize(4 * n + 1, 0); }
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
    if (ind <= mid)
      update(2 * index + 1, low, mid, ind, val);
    else
      update(2 * index + 2, mid + 1, high, ind, val);
    this->segarr[index] =
        max(this->segarr[2 * index + 1], this->segarr[2 * index + 2]);
  }
  int query(int index, int low, int high, int l, int r) {
    // no overlap
    if (r < low || l > high)
      return 0;

    // full overlap
    if (l <= low && high <= r)
      return this->segarr[index];

    // partial overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return max(left, right);
  }
};

class Solution {
public:
  int lengthOfLIS(vector<int> &nums, int k) {
    // using a segment tree based + dp approach where the segment array
    // acts like the dp table in LIS problem, we can take range maximum
    // of [num-k...num-1] which will give the possible maximum lis before
    // the current num
    int n = nums.size();
    const int N = 1e5;
    SGTree *sgtree = new SGTree(N);
    int maxi = 1;
    for (int i = 0; i < n; i++) {
      int num = nums[i];
      int max_lis_before = sgtree->query(0, 0, N, num - k, num - 1);
      sgtree->update(0, 0, N, num, max_lis_before + 1);
      maxi = max(maxi, sgtree->query(0, 0, N, num, num));
    }
    return maxi;
  }
};