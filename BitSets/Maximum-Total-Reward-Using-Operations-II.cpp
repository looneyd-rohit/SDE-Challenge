// Leetcode 3181

// Approach 1: bitsets masking
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

// Approach 2: further optimization (pruning)
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        const int sz = (int)5e4;
        sort(begin(rewardValues), end(rewardValues));
        bitset<sz> dp, mask;
        dp[0] = 1;
        int id = 0;
        int last = rewardValues.back();
        rewardValues.pop_back();
        for(auto& e: rewardValues){
            if(id < e){
                while(id < e) mask[id++] = 1;
                dp = dp | ((dp & mask) << e);
            }
        }
        int closest_sum = last - 1;
        while(!dp[closest_sum]) --closest_sum;
        return last + closest_sum;
    }
};