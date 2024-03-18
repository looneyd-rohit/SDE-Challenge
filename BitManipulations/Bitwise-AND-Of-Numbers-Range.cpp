// Leetcode 201

// Approach 1: calculating shifts
class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int no_of_shifts = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      no_of_shifts++;
    }
    return (left << no_of_shifts);
  }
};

// Approach 2: smart and unique approach
class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    while (left < right)
      right = right & (right - 1);
    return right;
  }
};