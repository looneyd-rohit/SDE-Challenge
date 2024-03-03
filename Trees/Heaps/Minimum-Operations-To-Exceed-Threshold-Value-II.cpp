// Leetcode 3066

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<long long, vector<long long>, greater<long long>> minheap;
    for (int i = 0; i < n; i++) {
      minheap.push(nums[i]);
    }
    int ops = 0;
    while (!minheap.empty()) {
      if (minheap.top() >= k)
        break;
      if (minheap.size() < 2)
        break;
      long long first = minheap.top();
      minheap.pop();
      long long second = minheap.top();
      minheap.pop();
      long long new_element =
          min(first, second) * 1LL * 2 + 1LL * max(first, second);
      minheap.push(new_element);
      ops++;
    }
    return ops;
  }
};