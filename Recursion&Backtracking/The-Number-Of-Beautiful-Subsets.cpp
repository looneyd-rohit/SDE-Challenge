// Leetcode 2597

// Approach: recursion + backtracking
class Solution {
public:
    int hash[2001];
    int solve(int i, int k, int n, vector<int>& nums){
        if(i == n) return 1;

        // take
        int take = 0;
        if(hash[nums[i]-k+1000] == 0){
            hash[nums[i]+1000]++;
            take = solve(i+1, k, n, nums);
            hash[nums[i]+1000]--;
        }
        // not take
        int not_take = solve(i+1, k, n, nums);

        return (take + not_take);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        memset(hash, 0, sizeof(hash));
        return solve(0, k, n, nums)-1;
    }
};