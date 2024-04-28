// Leetcode 3131

// Approach: brute force
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        return nums2[0]-nums1[0];
    }
};