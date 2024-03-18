// Leetcode 1649

// [IMP] Approach 1: khandani segment tree range sum
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
  const int M = 1e9 + 7;
  int binarySearch(vector<int> &nums, int val) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + ((high - low) >> 1);
      if (nums[mid] == val)
        return mid;
      else if (nums[mid] > val)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
  int createSortedArray(vector<int> &instructions) {
    int n = instructions.size();
    vector<int> sorted_instructions = instructions;
    sort(begin(sorted_instructions), end(sorted_instructions));
    SGTree sgtree(sorted_instructions.size());
    long long count = 0;
    for (auto &ins : instructions) {
      int sorted_ind = binarySearch(sorted_instructions, ins);
      int smaller_count =
          sgtree.query(0, 0, sorted_instructions.size() - 1, 0, sorted_ind - 1);
      int larger_count =
          sgtree.query(0, 0, sorted_instructions.size() - 1, sorted_ind + 1,
                       sorted_instructions.size() - 1);
      count += min(smaller_count, larger_count) % M;
      count %= M;
      // update the segment tree
      sgtree.update(0, 0, sorted_instructions.size() - 1, sorted_ind, 1);
    }
    return count;
  }
};

// [IMP] Approach 2: using merge sort