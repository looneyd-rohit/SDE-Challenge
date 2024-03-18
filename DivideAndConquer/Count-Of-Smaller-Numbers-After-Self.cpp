// Leetcode 315

// [IMP] Approach 1: using merge sort (decreasing sort)
class Solution {
public:
  vector<int> count;
  void merge(int left, int mid, int right, vector<pair<int, int>> &nums) {
    vector<pair<int, int>> arr1(mid - left + 1);
    vector<pair<int, int>> arr2(right - mid);
    for (int i = left; i <= mid; i++)
      arr1[i - left] = nums[i];
    for (int i = mid + 1; i <= right; i++)
      arr2[i - mid - 1] = nums[i];

    int i = 0, j = 0, k = left;
    int n1 = arr1.size(), n2 = arr2.size();
    while (i < n1 && j < n2) {
      if (arr1[i].first <= arr2[j].first) {
        nums[k++] = arr2[j++];
      } else {
        count[arr1[i].second] += n2 - j;
        nums[k++] = arr1[i++];
      }
    }
    while (i < n1) {
      nums[k++] = arr1[i++];
    }
    while (j < n2) {
      nums[k++] = arr2[j++];
    }
  }
  void mergeSort(int left, int right, vector<pair<int, int>> &nums) {
    if (left < right) {
      int mid = left + ((right - left) >> 1);
      mergeSort(left, mid, nums);
      mergeSort(mid + 1, right, nums);
      merge(left, mid, right, nums);
    }
  }
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<pair<int, int>> nums_pair;
    count.resize(n, 0);
    for (int i = 0; i < n; i++) {
      nums_pair.push_back({nums[i], i});
    }
    mergeSort(0, n - 1, nums_pair);
    return count;
  }
};

// [IMP] Approach 2: using segment trees
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
    return this->segarr[index] = (left + right);
  }
};
class Solution {
public:
  int binarySearchDecreasing(vector<pair<int, int>> &nums, int val, int ind) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + ((high - low) >> 1);
      if (nums[mid].first == val && nums[mid].second == ind)
        return mid;
      else if (nums[mid].first == val && nums[mid].second > ind)
        low = mid + 1;
      else if (nums[mid].first == val && nums[mid].second < ind)
        high = mid - 1;
      else if (nums[mid].first > val)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return -1;
  }
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    SGTree sgtree(n);
    vector<pair<int, int>> sorted_nums;
    for (int i = 0; i < n; i++) {
      sorted_nums.push_back({nums[i], i});
    }
    sort(rbegin(sorted_nums), rend(sorted_nums));
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      int ind = binarySearchDecreasing(sorted_nums, nums[i], i);
      int q = sgtree.query(0, 0, n - 1, ind + 1, n - 1);
      ans[i] = q;
      sgtree.update(0, 0, n - 1, ind, 1);
    }
    return ans;
  }
};