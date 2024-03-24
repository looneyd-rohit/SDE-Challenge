// Leetcode 2179

// [IMP] Approach: using segment trees + hashing index logic to get count
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
      this->segarr[index] = val;
      return;
    }
    int mid = low + ((high - low) >> 1);
    if (ind <= mid)
      update(2 * index + 1, low, mid, ind, val);
    else
      update(2 * index + 2, mid + 1, high, ind, val);
    this->segarr[index] =
        this->segarr[2 * index + 1] + this->segarr[2 * index + 2];
  }
  int query(int index, int low, int high, int l, int r) {
    // no overlap
    if (r < low || high < l)
      return 0;

    // full overlap
    if (l <= low && high <= r)
      return this->segarr[index];

    // partial overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return (left + right);
  }
};
class Solution {
public:
  long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    // segment tree based approach
    // for a particular index in an array, we will have good triplets
    // equal to the no. of elements present in left * no. present in right
    // but here, when we process some index i of nums1, we have to check
    // the presence of the common elements in nums2 present before index i in
    // nums1; to achieve that we will get the corresponding index j on nums2
    // for the same element e having index i in nums1 and then take the sum of
    // [0...j-1] to get the count; afterwards we will also update the segment
    // tree by marking index j on the tree
    int n = nums1.size();
    // map for storing value to index
    unordered_map<int, int> value_to_index;
    for (int i = 0; i < n; i++)
      value_to_index[nums2[i]] = i;
    SGTree *sgtree = new SGTree(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
      int e = nums1[i];
      int index_i = i, index_j = value_to_index[e];
      // get the count (range sum) of elements before e
      int left_count = sgtree->query(0, 0, n - 1, 0, index_j - 1);
      int garbage_on_left = index_i - left_count;
      int right_count = (n - index_j - 1) - garbage_on_left;
      total += left_count * 1LL * right_count;
      // update the tree index j
      sgtree->update(0, 0, n - 1, index_j, 1);
    }
    return total;
  }
};