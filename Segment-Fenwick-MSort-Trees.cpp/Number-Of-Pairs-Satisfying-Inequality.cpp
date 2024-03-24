// Leetcode 2426

// [IMP] Approach: khandani approach of finding count of numbers smaller than
// some other number + some constant
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
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
    int n = nums1.size();
    // rearrange the inequality --> we will seee
    // nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
    // now for a particular j we need to find i such that
    // nums[j] + diff >= nums[i]
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      nums[i] = nums1[i] - nums2[i];
    vector<int> sorted_nums = nums;
    sort(begin(sorted_nums), end(sorted_nums));
    SGTree *sgtree = new SGTree(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int val = nums[i] + diff;
      int ind = upper_bound(begin(sorted_nums), end(sorted_nums), val) -
                begin(sorted_nums);
      ind--; // since we calculated upper bound
      ans += sgtree->query(0, 0, n - 1, 0, ind);
      // update segment tree
      int up_ind = binarySearch(sorted_nums, nums[i]);
      sgtree->update(0, 0, n - 1, up_ind, 1);
    }
    return ans;
  }
};