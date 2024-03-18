// Leetcode 493

// [IMP] Approach 1: using modified merge sort
class Solution {
public:
  int merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> arr1, arr2;
    for (int i = low; i <= mid; i++)
      arr1.push_back(nums[i]);
    for (int i = mid + 1; i <= high; i++)
      arr2.push_back(nums[i]);
    int i = 0, j = 0, k = low, n1 = arr1.size(), n2 = arr2.size();
    int count = 0;
    // first calcualte reverse pairs then sort the array [low...mid...high]
    while (i < n1 && j < n2) {
      if (arr1[i] > 2LL * arr2[j]) {
        count += (n1 - i);
        j++;
      } else {
        i++;
      }
    }
    i = 0, j = 0;
    while (i < n1 && j < n2) {
      if (arr1[i] >= arr2[j]) {
        nums[k++] = arr2[j++];
      } else {
        nums[k++] = arr1[i++];
      }
    }
    while (i < n1)
      nums[k++] = arr1[i++];
    while (j < n2)
      nums[k++] = arr2[j++];
    return count;
  }
  int mergeSort(vector<int> &nums, int low, int high) {
    if (low < high) {
      int mid = low + ((high - low) >> 1);
      int left = mergeSort(nums, low, mid);
      int right = mergeSort(nums, mid + 1, high);
      int count = merge(nums, low, mid, high);
      return (left + right + count);
    }
    return 0;
  }
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
  }
};

// [IMP] Approach 2: using segment trees range sum
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
  int binarySearch(vector<long long> &nums, long long val) {
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
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    vector<long long> sorted_nums;
    for (auto &e : nums) {
      sorted_nums.push_back(e);
      sorted_nums.push_back(2LL * e);
    }
    sort(begin(sorted_nums), end(sorted_nums));
    SGTree sgtree(sorted_nums.size());
    int count = 0;
    for (auto &num : nums) {
      long long twice_num = 2LL * num;
      int twice_ind = binarySearch(sorted_nums, twice_num);
      count += sgtree.query(0, 0, sorted_nums.size() - 1, twice_ind + 1,
                            sorted_nums.size() - 1);
      // update the segment tree
      int ind = binarySearch(sorted_nums, num);
      sgtree.update(0, 0, sorted_nums.size() - 1, ind, 1);
    }
    return count;
  }
};