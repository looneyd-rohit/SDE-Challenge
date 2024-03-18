// Leetcode 2216

// Approach: using stacks
class Solution {
public:
  int minDeletion(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (st.empty())
        st.push(nums[i]);
      else {
        if ((st.size() + 1) & 1 || st.top() != nums[i])
          st.push(nums[i]);
      }
    }
    int deletions = n - st.size();
    if (st.size() & 1)
      return deletions + 1;
    return deletions;
  }
};