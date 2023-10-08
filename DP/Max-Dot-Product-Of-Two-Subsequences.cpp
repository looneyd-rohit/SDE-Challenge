// Leetcode 1458

class Solution {
public:
    int dp[501][501][2];
    int solve(int i, int j, int len, vector<int>& nums1, vector<int>& nums2){
        // base case
        if(i == -1 || j == -1){
            if(len == 0) return -1e9;
            return 0;
        }

        // dp check
        if(dp[i][j][len]!=-1) return dp[i][j][len];

        int a = nums1[i] * nums2[j] + solve(i-1, j-1, 1, nums1, nums2);
        int b = solve(i, j-1, len, nums1, nums2);
        int c = solve(i-1, j, len, nums1, nums2);
        return dp[i][j][len] = max({a, b, c});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solve(n1-1, n2-1, 0, nums1, nums2);
    }
};