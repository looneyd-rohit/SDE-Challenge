// Leetcode 1690
// [IMP]: DP with difference of scores pattern

// Approach 1:

class Solution {
public:
    int dp[1001][1001][2];
    int solve(int i, int j, bool isAlice, vector<int>& prefix){
        // base case
        if(i > j) return 0;
        
        // base case
        if(dp[i][j][isAlice]!=-1) return dp[i][j][isAlice];
        
        if(isAlice){
            // alice's turn
            int rightPart = prefix[j] - prefix[i];
            int leftPart = (j > 0 ? prefix[j-1] : 0) - (i > 0 ? prefix[i-1] : 0);
            // alice's score gets added +ve ly
            return dp[i][j][isAlice] = max({rightPart + solve(i+1, j, !isAlice, prefix), leftPart + solve(i, j-1, !isAlice, prefix)});
        }else{
            // bob's turn
            int rightPart = prefix[j] - prefix[i];
            int leftPart = (j > 0 ? prefix[j-1] : 0) - (i > 0 ? prefix[i-1] : 0);
            // bob's score gets added -ve ly
            return dp[i][j][isAlice] = min({-rightPart + solve(i+1, j, !isAlice, prefix), -leftPart + solve(i, j-1, !isAlice, prefix)});
        }
    }
    int stoneGameVII(vector<int>& stones) {
        // assume solve() to return alice's maximum score that can be obtained
        int n = stones.size();
        // prefix sum
        vector<int> prefix(n, stones[0]);
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + stones[i];
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, true, prefix);
    }
};

// Approach 2: slight improvement, we can recurse the -ve operation instead of
// adding for one and subtracting for another

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, vector<int>& prefix){
        // base case
        if(i > j) return 0;
        
        // base case
        if(dp[i][j]!=-1) return dp[i][j];
        
        // since we need the difference in score, we can recurse the -ve operation
        // instead of adding score for alice and subtracting for bob
        int rightPart = prefix[j] - prefix[i];
        int leftPart = (j > 0 ? prefix[j-1] : 0) - (i > 0 ? prefix[i-1] : 0);
        // alice's score gets added +ve ly
        return dp[i][j] = max({rightPart - solve(i+1, j, prefix), leftPart - solve(i, j-1, prefix)});
    }
    int stoneGameVII(vector<int>& stones) {
        // assume solve() to return alice's maximum score that can be obtained
        int n = stones.size();
        // prefix sum
        vector<int> prefix(n, stones[0]);
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + stones[i];
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, prefix);
    }
};