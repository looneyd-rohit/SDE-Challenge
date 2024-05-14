// Leetcode 3129

// [IMP] Approach 1: top down 3D dp without much optimization
class Solution {
public:
    const int M = 1e9+7;
    long long dp[201][201][2];
    long long dfs(int zero, int one, int ll, int pr){
        if(zero == 0 && one == 0) return 1;

        if(dp[zero][one][pr]!=-1) return dp[zero][one][pr];
        
        if(pr == 1){
            long long a = 0;
            for(int i=1; i<=min(zero, ll); i++){
                a += dfs(zero-i, one, ll, 0) % M;
                a %= M;
            }
            return dp[zero][one][pr] = a;
        }else{
            long long a = 0;
            for(int i=1; i<=min(one, ll); i++){
                a += dfs(zero, one-i, ll, 1) % M;
                a %= M;
            }
            return dp[zero][one][pr] = a;
        }
        return 0;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        long long a = 0;
        a += dfs(zero, one, limit, 1) % M;
        a %= M;
        memset(dp, -1, sizeof(dp));
        a += dfs(zero, one, limit, 0) % M;
        a %= M;
        return a % M;
    }
};

// [IMP] Approach 2: bottom up 3D dp without much optimization
class Solution {
public:
    const int M = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        long long dp[201][201][2];
        memset(dp, 0, sizeof(dp));

        // base case
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {
                if (z == 0 && o == 0) continue;
                for (int i = 1; i <= min(z, limit); i++) {
                    dp[z][o][1] += dp[z - i][o][0] % M;
                    dp[z][o][1] %= M;
                }
                for (int i = 1; i <= min(o, limit); i++) {
                    dp[z][o][0] += dp[z][o - i][1] % M;
                    dp[z][o][0] %= M;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % M;
    }
};