// Leetcode 2731

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        // similar to leetcode 1503 ants problem
        const int M = 1e9+7;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(s[i]=='L') nums[i] -= d;
            else nums[i] += d;
        }
        sort(begin(nums), end(nums));
        reverse(begin(nums), end(nums));
        // summation of sigma(a[i]*(n-(2*i+1)))
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long e = nums[i] * 1LL * (n - (2*i+1));
            e %= M;
            ans += e;
            ans %= M;
            ans += M;
            ans %= M;
        }
        return ans % M;
    }
};