// Leetcode 920
// [IMP]: DP with numbers
class Solution {
public:
    const int M = 1e9+7;
    int dp[101][101];
    long long solve(int len, int num, int k, int n, int goal){
        // base case
        if(len == goal){
            if(num == n) return 1;
            return 0;
        }

        // dp check
        if(dp[len][num]!=-1) return dp[len][num];

        long long first = ((solve(len + 1, num, k, n, goal) % M) * max(0, num - k)) % M;

        long long second = ((solve(len + 1, num + 1, k, n, goal) % M) * (n - num)) % M;

        long long ans = (first + second) % M;

        return dp[len][num] = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        // memeoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, n, goal);
    }
};