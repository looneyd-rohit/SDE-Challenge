// Leetcode 3181

// Approach: bitsets masking
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        const int sz = (int)1e5+1;
        sort(begin(rewardValues), end(rewardValues));
        bitset<sz> dp, prev, mask;
        dp[0] = 1;
        int id = 0;
        for(auto& e: rewardValues){
            while(id < e) mask[id++] = 1;
            prev = dp & mask;
            dp = dp | (prev << e);
        }
        int maxi = 1e5;
        while(!dp[maxi]) --maxi;
        return maxi;
    }
};