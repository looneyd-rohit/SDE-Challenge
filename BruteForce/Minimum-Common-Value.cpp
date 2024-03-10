// Leetcode 2540

// Approach 1: using hashset
class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    unordered_set<int> ust(begin(nums1), end(nums1));
    for (auto &e : nums2)
      if (ust.count(e))
        return e;
    return -1;
  }
};

// Approach 2: using binary search
class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    for (int i = 0; i < n1; i++) {
      if (binary_search(begin(nums2), end(nums2), nums1[i])) {
        return nums1[i];
      }
    }
    return -1;
  }
};

// Approach 3: using two pointers (merging two sorted arrays approach)
class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
      if (nums1[i] < nums2[j]) {
        i++;
      } else if (nums1[i] > nums2[j]) {
        j++;
      } else {
        return nums1[i];
      }
    }
    return -1;
  }
};