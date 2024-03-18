// Leetcode 1340

// [IMP] Approach: top down is normal but bottom up needs sorting
class Solution {
public:
  int dp[1001];
  int solve(int index, int d, int n, vector<int> &arr) {
    if (dp[index] != -1)
      return dp[index];
    int jump = 1;
    // left jump
    for (int i = index - 1; i >= max(0, index - d) && arr[i] < arr[index];
         i--) {
      jump = max(jump, 1 + solve(i, d, n, arr));
    }
    // right jump
    for (int i = index + 1; i <= min(n - 1, index + d) && arr[i] < arr[index];
         i++) {
      jump = max(jump, 1 + solve(i, d, n, arr));
    }
    return dp[index] = jump;
  }
  int maxJumps(vector<int> &arr, int d) {
    int n = arr.size();
    // memset(dp, -1, sizeof(dp));
    // int maxi = 0;
    // for(int i=0; i<n; i++){
    //     maxi = max(maxi, solve(i, d, n, arr));
    // }
    // return maxi;

    // bottom up
    memset(dp, 0, sizeof(dp));
    int maxi = 0;
    vector<pair<int, int>> arr_with_idx;
    for (int i = 0; i < n; i++)
      arr_with_idx.push_back({arr[i], i});
    sort(begin(arr_with_idx), end(arr_with_idx));
    // we need to sort the array in bottom up, since we can only go from larger
    // height to smaller height we need to have the value of smaller height
    // first which will ensure that at larger height answer can be stored
    for (int i = 0; i < n; i++) {
      int index = arr_with_idx[i].second;
      int jump = 1;
      // left jump
      for (int j = index - 1; j >= max(0, index - d) && arr[j] < arr[index];
           j--) {
        jump = max(jump, 1 + dp[j]);
      }
      // right jump
      for (int j = index + 1; j <= min(n - 1, index + d) && arr[j] < arr[index];
           j++) {
        jump = max(jump, 1 + dp[j]);
      }
      dp[index] = jump;
      maxi = max(maxi, dp[index]);
    }
    return maxi;
  }
};