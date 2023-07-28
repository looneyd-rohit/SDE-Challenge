// Leetcode 1879
// [IMP]: DP + Bitmask
class Solution {
public:
    int dp[14][1<<14+1];
    int solve(int index, int mask, int n, vector<int>& nums1, vector<int>& nums2){
        // base case
        if(index >= n){
            return 0;
        }
        // dp check
        if(dp[index][mask]!=-1) return dp[index][mask];
        
        int ans = 1e9;
        for(int i=0; i<n; i++){
            if(mask & (1<<i)){
                // already taken
            }else{
                int sum = (nums1[index] ^ nums2[i]) + solve(index+1, mask ^ (1<<i), n, nums1, nums2);
                ans = min(ans, sum);
            }
        }
        return dp[index][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, nums1, nums2);
    }
};