// Leetcode 1074

// [IMP] Approach: sliding window + concept of subarray sum equals k on 2D array
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    // similar approach to no. of subarrays with sum k
    // take a starting point and go on finding sum
    // then see possibilities
    // but here we need to fix one direction since two ways we cannot
    // track in a hashmap
    // find the row-wise prefix sum to make one direction obsolete
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }
    long long count = 0;
    for (int col = 0; col < n; col++) {
      for (int j = col; j < n; j++) {
        // applying subarray sum equals k logic to each column
        // with starting point of submatrix at col
        unordered_map<long long, long long> hash;
        hash[0] = 1;
        long long sum = 0;
        for (int i = 0; i < m; i++) {
          sum += matrix[i][j] - (col > 0 ? matrix[i][col - 1] : 0);
          ;
          long long req = sum - target;
          if (hash.find(req) != hash.end()) {
            count += hash[req];
          }
          hash[sum]++;
        }
      }
    }

    return count;
  }
};