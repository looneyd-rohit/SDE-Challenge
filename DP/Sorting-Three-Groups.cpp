// Leetcode 2826
// [IMP]: Nice pattern on DP
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int dp[101][4] = {0};    // dp[i][k] stores count of k till i-th index
        for(int i=0; i<n; i++){
            for(int k=1; k<4; k++){
                if(nums[i] == k){
                    dp[i+1][k] = 1 + dp[i][k];
                }else{
                    dp[i+1][k] = dp[i][k];
                }
            }
        }
        int ans = 1e9;
        for(int i=0; i<=n; i++){
            for(int j=i; j<=n; j++){
                for(int k=j; k<=n; k++){
                    int ones = dp[i][1];
                    int twos = dp[j][2] - dp[i][2];
                    int threes = dp[k][3] - dp[j][3];
                    ans = min(ans, n-ones-twos-threes);
                }
            }
        }
        return ans;
    }
};