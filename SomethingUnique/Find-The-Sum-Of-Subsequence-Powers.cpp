// Leetcode 3098

// [IMP] Approach: dp + superset/subset handling
class Solution {
public:
    const int M = 1e9+7;
    int dp[52][52][52];
    // f(index, last_ind, k) -> count of subsequences with adjacent diff >= d
    long long f(int index, int last_ind, int k, int d, int n, vector<int>& nums){
        if(k == 0) return 1;
        if(index == n) return 0;

        if(dp[index][last_ind+1][k]!=-1) return dp[index][last_ind+1][k];

        // not take
        long long not_take = f(index+1, last_ind, k, d, n, nums) % M;

        // take
        long long take = 0;
        if(last_ind==-1 || (nums[index] - nums[last_ind]>=d)){
            take = f(index+1, index, k-1, d, n, nums) % M;
        }
        return dp[index][last_ind+1][k] = (take + not_take) % M;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        set<int> diff;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                diff.insert(nums[j]-nums[i]);
            }
        }
        int ans = 0;
        int prev_cnt = 0;
        // wtf bruh -> O(n^5) works :/
        for(auto it=diff.rbegin(); it!=diff.rend(); it++){
            memset(dp, -1, sizeof(dp));

            long long d = *it;

            long long cnt = f(0, -1, k, d, n, nums);

            // previous count subtracted since current is a superset so
            // double counting is prevented
            ans += (((cnt - prev_cnt + M) % M) * 1LL * d) % M;
            ans %= M;

            prev_cnt = cnt;
        }
        return ans;
    }
};

// [IMP] Approach 2: previous approach optimization using binary search
class Solution {
public:
    const int M = 1e9+7;
    int dp[52][52];
    // f(index, last_ind, k) -> count of subsequences with adjacent diff >= d
    long long f(int index, int k, int d, int n, vector<int>& nums){
        if(k == 0) return 1;
        if(index == n) return 0;

        if(dp[index][k]!=-1) return dp[index][k];

        // not take
        long long not_take = f(index+1, k, d, n, nums) % M;

        // take
        int ind = lower_bound(begin(nums), end(nums), nums[index]+d) - begin(nums);
        long long take = f(ind, k-1, d, n, nums) % M;

        return dp[index][k] = (take + not_take) % M;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        set<int> diff;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                diff.insert(nums[j]-nums[i]);
            }
        }
        int ans = 0;
        int prev_cnt = 0;
        // wtf bruh -> O(n^5) works :/
        // optimization using binary search lower bound -> O(n^4) 🚀
        for(auto it=diff.rbegin(); it!=diff.rend(); it++){
            memset(dp, -1, sizeof(dp));

            long long d = *it;

            long long cnt = f(0, k, d, n, nums);

            // previous count subtracted since current is a superset so
            // double counting is prevented
            ans += (((cnt - prev_cnt + M) % M) * 1LL * d) % M;
            ans %= M;

            prev_cnt = cnt;
        }
        return ans;
    }
};