// Leetcode 3147

// Approach: simple dp
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        for(int i=n-k; i<n; i++) dp[i] = energy[i];
        for(int i=n-1; i>=0; i--){
            int curr = energy[i];
            if(i+k < n) curr += dp[i+k];
            dp[i] = curr;
        }
        return *max_element(begin(dp), end(dp));
    }
};