// Leetcode 1510
// [IMP]: Choose DP (choose b/w alice and bob and make decisions)

class Solution {
public:
    int dp[(int)1e5+1][2];
    bool solve(int n, bool isAlice){
        // base case
        if(n == 0){
            if(!isAlice) return true;    // previous turn was by alice
            return false;
        }
        
        // dp check
        if(dp[n][isAlice]!=-1) return dp[n][isAlice];
        
        // pick a square number as close to n
        if(isAlice){
            bool ans = false;    // assume bob wins and try for any combination
            // that can make alice win, because motive is to make him win
            for(int num=1; num*num<=n; num++){
                ans = ans || solve(n-num*num, !isAlice);
            }
            return dp[n][isAlice] = ans;
        }else{
            bool ans = true;    // assume alice wins and try for any combination
            // that can make bob win, because motive is to make alice lose
            for(int num=1; num*num<=n; num++){
                ans = ans && solve(n-num*num, !isAlice);
            }
            return dp[n][isAlice] = ans;
        }
    }
    bool winnerSquareGame(int n) {
        // a function solve() that returns true if alice wins and false if bob wins
        // fixing the function behaviour, true --> alice wins no matter what is the input
        // false --> bob wins no matter what is the input
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(n, true);
    }
};