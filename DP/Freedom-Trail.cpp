// Leetcode 514

// Approach: dp + try all possibilities + little logic
class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int n, int m, string& ring, string& key){
        if(j == m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        // try all possible steps
        int ans = 1e9;
        for(int index=0; index<n; index++){
            if(ring[index]==key[j]){
                int cost = min({(index-i+n)%n, (n-index+i)%n, (n-i+index)%n});
                ans = min(ans, cost + solve(index, j+1, n, m, ring, key));
            }
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        int ans = 1e9;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, m, ring, key) + key.length();
    }
};