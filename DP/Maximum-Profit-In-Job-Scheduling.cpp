// Leetcode 1235

class Solution {
public:
    int dp[(int)(1e5+5)];
    int solve(int index, int n, vector<vector<int>>& store){
        // base case
        if(index >= n){
            return 0;
        }
        // dp check
        if(dp[index]!=-1) return dp[index];
        int ans = 0;
        int low = index+1, high = n-1;
        while(low <= high){
            int mid = low + ((high-low) >> 1);
            if(store[mid][0] >= store[index][1]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        // notTake
        ans = max(ans, solve(index+1, n, store));
        // take
        ans = max(ans, store[index][2] + solve(low, n, store));
        return dp[index] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> store;
        for(int i=0; i<n; i++){
            store.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(begin(store), end(store));
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, n, store);
    }
};