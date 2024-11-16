// Leetcode 486
// [IMP]: Choose DP
class Solution {
public:
    int dp[21][21][2];
    int solve(int i, int j, bool isFirst, vector<int>& nums){
        // base case
        if(i > j) return 0;
        
        // dp check
        if(dp[i][j][isFirst]!=-1) return dp[i][j][isFirst];
        
        int ans = -1e9;
        if(isFirst){
            // player 1 --> maximize player 1
            ans = max(nums[i] + solve(i+1, j, !isFirst, nums), nums[j] + solve(i, j-1, !isFirst, nums));
        }else{
            // player 2 --> minimize player 2
            ans = 0 + min(solve(i+1, j, !isFirst, nums), solve(i, j-1, !isFirst, nums));
        }
        return dp[i][j][isFirst] = ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // write a function solve() which will return the score of the player 1
        int total = 0;
        for(auto& e: nums) total += e;
        // memeoization:
        memset(dp, -1, sizeof(dp));
        int player1 = solve(0, n-1, true, nums);
        int player2 = total - player1;
        return player1 >= player2;
    }
};