// Leetcode 1911
// Standard Knapsack 0/1 Pattern

// Memoization:
class Solution {
public:
    long long solve(int index, int takenSoFar, vector<int>& nums, vector<vector<long long>>& dp){
        // base case
        if(index >= nums.size()){
            return 0;
        }
        
        // dp check
        if(dp[index][takenSoFar]!=-1) return dp[index][takenSoFar];
        
        // take
        // take has two possibilities --> odd index, even index
        long long take = 0;
        if(takenSoFar & 1){
            // odd index --> element to be added gets subtracted actually
            take = -nums[index] + solve(index+1, (takenSoFar+1)&1, nums, dp);
        }else{
            // even index --> element to be added gets added actually
            take = nums[index] + solve(index+1, (takenSoFar+1)&1, nums, dp);
        }
        
        // don't take
        long long dontTake = solve(index+1, takenSoFar&1, nums, dp);
        
        return dp[index][takenSoFar] = max(take, dontTake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // memoization:
        // fun fact: we don't need takenSoFar count, as we only want to know whether the
        // particular index we are taking is even or odd, so a boolean type variable will
        // be sufficient
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 0, nums, dp);
    }
};

// Tabulation:
class Solution {
public:
    long long solve(int index, int takenSoFar, vector<int>& nums, vector<vector<long long>>& dp){
        // base case
        if(index >= nums.size()){
            return 0;
        }
        
        // dp check
        if(dp[index][takenSoFar]!=-1) return dp[index][takenSoFar];
        
        // take
        // take has two possibilities --> odd index, even index
        long long take = 0;
        if(takenSoFar & 1){
            // odd index --> element to be added gets subtracted actually
            take = -nums[index] + solve(index+1, (takenSoFar+1)&1, nums, dp);
        }else{
            // even index --> element to be added gets added actually
            take = nums[index] + solve(index+1, (takenSoFar+1)&1, nums, dp);
        }
        
        // don't take
        long long dontTake = solve(index+1, takenSoFar&1, nums, dp);
        
        return dp[index][takenSoFar] = max(take, dontTake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // memoization:
        // fun fact: we don't need takenSoFar count, as we only want to know whether the
        // particular index we are taking is even or odd, so a boolean type variable will
        // be sufficient
        // vector<vector<long long>> dp(n, vector<long long>(2, -1));
        // return solve(0, 0, nums, dp);
        
        // tabulation:
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        for(int index=n-1; index>=0; index--){
            for(int takenSoFar=1; takenSoFar>=0; takenSoFar--){
                // take
                // take has two possibilities --> odd index, even index
                long long take = 0;
                if(takenSoFar & 1){
                    // odd index --> element to be added gets subtracted actually
                    take = -nums[index] + dp[index+1][(takenSoFar+1)&1];
                }else{
                    // even index --> element to be added gets added actually
                    take = nums[index] + dp[index+1][(takenSoFar+1)&1];
                }

                // don't take
                long long dontTake = dp[index+1][(takenSoFar&1)];

                dp[index][takenSoFar] = max(take, dontTake);
            }
        }
        return dp[0][0];
    }
};