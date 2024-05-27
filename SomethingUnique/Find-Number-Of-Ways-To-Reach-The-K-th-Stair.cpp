// Leetcode 3154

// Approach: recursion with presence of cycle (multiple counting)
// https://www.youtube.com/watch?v=IerW9bBV8qk
class Solution {
public:
    vector<vector<unordered_map<int, int>>> dp;
    int solve(int pos, int jump, bool flag, int k){
        if((1LL<<jump) > k+1){
            if(pos==k) return 1;
            if(pos==k+1 && flag) return 1;
            return 0;
        }

        if(dp[jump][flag].find(pos)!=dp[jump][flag].end()) return dp[jump][flag][pos];

        int backwards = 0;
        if(flag && pos > 0) backwards = solve(pos-1, jump, false, k);

        int forwards = solve(pos+(1LL<<jump), jump+1, true, k);

        return dp[jump][flag][pos] = (backwards + forwards) + (pos == k);
    }
    int waysToReachStair(int k) {
        if(k == 0) return 2;
        dp.resize(32, vector<unordered_map<int, int>>(2));
        return solve(1, 0, true, k);
    }
};