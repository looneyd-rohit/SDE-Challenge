// Leetcode 3130

// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/solutions/5084709/c-easy-2d-dp-detailed-explanation-with-pictures-images-80-ms

// [IMP] Approach: dp + optimization by sliding window + prefix sum (3D --> 2D)
class Solution {
public:
    const int M = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        // one of the hardest --> 🔥 too much edge case handling
        // for optimizing the O(n) part to --> O(1) 🚀
        long long dp[zero+1][one+1][2];
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {
                if (z == 0 && o == 0) continue;

                if(z < limit){
                    if(z > 0){
                        dp[z][o][1] = dp[z-1][o][0];
                        if(z > 1){
                            dp[z][o][1] += dp[z-1][o][1];
                        }
                    }
                }else if(z == limit){
                    if(z > 0){
                        dp[z][o][1] = dp[z-1][o][0];
                        if(limit > 1){
                            dp[z][o][1] += dp[z-1][o][1];
                        }
                    }
                }else if(z > limit){
                    dp[z][o][1] = dp[z-1][o][0];
                    if(limit > 1){
                        dp[z][o][1] += dp[z-1][o][1] - dp[z-1-limit][o][0];
                    }
                }
                dp[z][o][1] %= M;
                dp[z][o][1] += M;
                dp[z][o][1] %= M;


                if(o < limit){
                    if(o > 0){
                        dp[z][o][0] = dp[z][o-1][1];
                        if(o > 1){
                            dp[z][o][0] += dp[z][o-1][0];
                        }
                    }
                }else if(o == limit){
                    if(o > 0){
                        dp[z][o][0] = dp[z][o-1][1];
                        if(limit > 1){
                            dp[z][o][0] += dp[z][o-1][0];
                        }
                    }
                }else if(o > limit){
                    dp[z][o][0] = dp[z][o-1][1];
                    if(limit > 1){
                        dp[z][o][0] += dp[z][o-1][0] - dp[z][o-1-limit][1];
                    }
                }
                dp[z][o][0] %= M;
                dp[z][o][0] += M;
                dp[z][o][0] %= M;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % M;
    }
};
