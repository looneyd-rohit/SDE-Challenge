// Leetcode 3065

// Approach 1: using minheap
class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minheap;
    int ops = 0;
    for (int i = 0; i < n; i++) {
      minheap.push(nums[i]);
      if (minheap.top() < k) {
        minheap.pop();
        ops++;
      }
    }
    return ops;
  }
};

// Approach 2: simple O(N)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ops = 0;
        for(int i=0; i<n; i++){
            if(nums[i]<k){
                ops++;
            }
        }
        return ops;
    }
};