// Leetcode 338

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            // i&(i-1) -> the no which has one less set bits than i, because the last
            // bit from i is removed in i&(i-1)
            ans[i] = ans[i&(i-1)] + 1;
        }
        return ans;
    }
};