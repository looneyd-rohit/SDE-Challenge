// Leetcode 349

// Approac 1: using hashset
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
      if (m.count(a)) {
        res.push_back(a);
        m.erase(a);
      }
    return res;
  }
};

// Approach 2: sorting + two pointers
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    int i = 0, j = 0;
    vector<int> result;
    while (i < n1 && j < n2) {
      if (nums1[i] < nums2[j])
        i++;
      else if (nums1[i] > nums2[j])
        j++;
      else {
        result.push_back(nums1[i]);
        while (i < n1 - 1 && nums1[i] == nums1[i + 1])
          i++;
        while (j < n2 - 1 && nums2[j] == nums2[j + 1])
          j++;
        i++;
        j++;
      }
    }
    return result;
  }
};