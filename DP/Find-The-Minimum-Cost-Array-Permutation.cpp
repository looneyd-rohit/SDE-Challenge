// Leetcode 3149

// Approach: observation + bit mask + dp + optimization
class Solution {
public:
    int dp[14][(1<<14)];
    int path[14][(1<<14)];
    int solve(int prev, int mask, int full_mask, int n, vector<int>& nums){
        if(mask == full_mask) return 0;

        if(dp[prev][mask]!=-1) return dp[prev][mask];

        int ans = INT_MAX;

        if(mask == 0){
            path[prev][mask] = 0;
            return dp[prev][mask] = solve(0, mask | (1<<0), full_mask, n, nums);
        }else{
            for(int curr=0; curr<n; curr++){
                if(mask & (1<<curr)) continue;

                int score = 0;
                if(mask > 0){
                    // not the first position
                    score += abs(prev - nums[curr]);
                }
                if((mask | (1<<curr)) == full_mask){
                    // end element
                    score += abs(curr - nums[0]);
                }
                // recursive call
                score += solve(curr, mask | (1 << curr), full_mask, n, nums);

                if(score < ans){
                    ans = score;
                    path[prev][mask] = curr;
                }
            }
            return dp[prev][mask] = ans;
        }


    }
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        // note: by observation, we see that there can exist multiple permutations
        // having minimum score, also each of them will be cyclic shifts of one another,
        // hence the exact position does not affect the score, only their relative positions
        // affect the score; hence we can say there will always exist a permutation with 0 as the
        // first element and that will be the lexicographically smallest :)
        solve(0, 0, (1<<n)-1, n, nums);
        vector<int> result(n, 0);
        // initialize the initial state
        int prev = 0, mask = 0;
        for(int i=0; i<n; i++){
            int p = path[prev][mask];
            result[i] = p;
            prev = p;
            mask = mask | (1 << p);
        }
        return result;
    }
};