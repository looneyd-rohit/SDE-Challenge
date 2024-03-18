// Leetcode 327

// [IMP] Approach 1: storing in a set to avoid duplicates, then numbering of
// duplicates and classic approach
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
        this->segarr[2 * index + 1] + this->segarr[2 * index + 2];
  }
  void update(int index, int low, int high, int ind, int val) {
    if (low == high) {
      this->segarr[index] += val;
      return;
    }

    int mid = low + ((high - low) >> 1);
    if (ind <= mid) {
      update(2 * index + 1, low, mid, ind, val);
    } else {
      update(2 * index + 2, mid + 1, high, ind, val);
    }
    this->segarr[index] =
        this->segarr[2 * index + 1] + this->segarr[2 * index + 2];
  }
  int query(int index, int low, int high, int l, int r) {
    // no overlap
    if (r < low || high < l) {
      return 0;
    }

    // full overlap
    if (l <= low && high <= r) {
      return this->segarr[index];
    }

    // partial overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return (left + right);
  }
};

class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();

    // calculate prefix sums
    vector<long long> prefix_nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefix_nums[i] = prefix_nums[i - 1] + nums[i - 1];

    set<long long> sorted_prefix;
    for (int i = 0; i <= n; i++) {
      sorted_prefix.insert(prefix_nums[i]);
      sorted_prefix.insert(prefix_nums[i] - lower);
      sorted_prefix.insert(prefix_nums[i] - upper);
    }

    int sorted_prefix_size = 0;
    unordered_map<long long, int> ump;
    for (auto &sum : sorted_prefix) {
      ump[sum] = sorted_prefix_size++;
    }

    // initialize segment tree
    SGTree sgtree(sorted_prefix_size);

    int count = 0;
    // we need to count possibilities for a particular index
    // in the range [sum-upper ... sum-lower] in the left side
    // of every sum (to avoid duplication)
    for (auto &p : prefix_nums) {
      int left = ump[p - upper];
      int right = ump[p - lower];
      count += sgtree.query(0, 0, sorted_prefix_size - 1, left, right);
      // update segtree
      int ind = ump[p];
      sgtree.update(0, 0, sorted_prefix_size - 1, ind, 1);
    }

    return count;
  }
};

// [IMP] Approach 2: using modified merge sort