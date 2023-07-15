// Leetcode 1751
// [IMP]: Knapsack 0/1 DP pattern
class Solution {
public:
    int solve(int index, vector<vector<int>>& events, int k, vector<vector<int>>& dp){
        // base case
        if(index >= events.size()) return 0;
        
        // all items taken
        if(k == 0) return 0;
        
        // dp check
        if(dp[index][k]!=-1) return dp[index][k];
        
        
        // pick
        int pick = events[index][2];
        // now call for the next index which can be picked
        int low = index+1, high = events.size()-1;
        while(low<=high){
            int mid = low + ((high-low)>>1);
            if(events[mid][0] > events[index][1]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        pick += solve(low, events, k-1, dp);
        
        
        // notPick
        int notPick = 0 + solve(index+1, events, k, dp);
        
        return dp[index][k] = max(pick, notPick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(begin(events), end(events));
        // memoization:
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return solve(0, events, k, dp);
    }
};