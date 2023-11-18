// Leetcode 2926

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sums(n, 0);
        for(int i=0; i<n; i++) sums[i] = nums[i];
        long long maxi = *max_element(begin(nums), end(nums));
        map<int, long long> mp;
        for(int i=0; i<n; i++){
            int d = nums[i] - i;
            auto it = mp.upper_bound(d);
            long long curr_sum = nums[i];
            if(it != begin(mp)){
                it--;    // go to prev term such that it is <= current term
                curr_sum += it->second;
            }

            // update in map for curr_sum
            mp[nums[i]-i] = max(mp[nums[i]-i], curr_sum);

            // update answer
            maxi = max(maxi, curr_sum);

            // remove all the next elements where sum <= curr_sum
            it = mp.upper_bound(d);

            while(it!=end(mp) && it->second <= curr_sum) mp.erase(it++);
        }
        return maxi;
    }
};