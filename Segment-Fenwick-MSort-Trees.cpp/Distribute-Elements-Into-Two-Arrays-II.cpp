// Leetcode 3072
// [IMP] Approach: segment tree + logic to find count
// of greater numbers before self
class SGTreeSum {
public:
  vector<int> segArr;
  SGTreeSum() { segArr.resize(1e5 + 1, 0); }
  SGTreeSum(int n) { segArr.resize(4 * n + 1, 0); }

  void build(int index, int low, int high, vector<int> &arr) {
    // base case
    if (low == high) {
      // if range size is 1, current element is minimum
      segArr[index] = arr[low];
      return;
    }

    int mid = (low) + ((high - low) >> 1);

    // left subtree
    int index1 = 2 * index + 1;
    build(index1, low, mid, arr);

    // right subtree
    int index2 = 2 * index + 2;
    build(index2, mid + 1, high, arr);

    segArr[index] = segArr[index1] + segArr[index2];
  }

  int query(int index, int low, int high, int l, int h) {
    // no overlap
    if (h < low || l > high) {
      return 0;
    }

    // full overlap
    if (l <= low and high <= h) {
      return segArr[index];
    }

    // partial overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2 * index + 1, low, mid, l, h);
    int right = query(2 * index + 2, mid + 1, high, l, h);
    return left + right;
  }

  void update(int index, int low, int high, int i, int val) {
    // base case
    if (low == high) {
      // update at actual position
      segArr[index] += val;
      return;
    }

    int mid = low + ((high - low) >> 1);

    if (i <= mid) {
      update(2 * index + 1, low, mid, i, val);
    } else {
      update(2 * index + 2, mid + 1, high, i, val);
    }

    // update the new minimum
    segArr[index] = segArr[2 * index + 1] + segArr[2 * index + 2];
  }
};

class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    int n = nums.size();
    SGTreeSum sg_left(n), sg_right(n);
    // no need to build separately as all values are 0 initially
    vector<int> copy_nums;
    for (int i = 0; i < n; i++)
      copy_nums.push_back(nums[i]);
    sort(begin(copy_nums), end(copy_nums));
    vector<int> left, right;
    // first and second element are always exception
    int first = nums[0], second = nums[1];
    left.push_back(first);
    int first_ind =
        lower_bound(begin(copy_nums), end(copy_nums), first) - begin(copy_nums);
    sg_left.update(0, 0, n - 1, first_ind, 1);
    right.push_back(second);
    int second_ind = lower_bound(begin(copy_nums), end(copy_nums), second) -
                     begin(copy_nums);
    sg_right.update(0, 0, n - 1, second_ind, 1);
    for (int i = 2; i < n; i++) {
      int el = nums[i];
      int el_ind =
          lower_bound(begin(copy_nums), end(copy_nums), el) - begin(copy_nums);
      int el_greater_ind =
          upper_bound(begin(copy_nums), end(copy_nums), el) - begin(copy_nums);

      int left_count = sg_left.query(0, 0, n - 1, el_greater_ind, n - 1);
      int right_count = sg_right.query(0, 0, n - 1, el_greater_ind, n - 1);
      if (left_count > right_count) {
        left.push_back(el);
        sg_left.update(0, 0, n - 1, el_ind, 1);
      } else if (left_count < right_count) {
        right.push_back(el);
        sg_right.update(0, 0, n - 1, el_ind, 1);
      } else {
        if (left.size() <= right.size()) {
          left.push_back(el);
          sg_left.update(0, 0, n - 1, el_ind, 1);
        } else {
          right.push_back(el);
          sg_right.update(0, 0, n - 1, el_ind, 1);
        }
      }
    }
    vector<int> result;
    for (auto &e : left)
      result.push_back(e);
    for (auto &e : right)
      result.push_back(e);
    return result;
  }
};