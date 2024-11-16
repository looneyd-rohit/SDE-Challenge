// Leetcode 1478

// Approach [IMP]: Very nice DP problem + Front partition + Median Based (maths)
class Solution {
public:
    int dp[(int)1e4+1][101];
    int solve(int index, int k, int n, vector<int>& houses){
        // base case
        if(index >= n){
            // if index is exhausted and we were successful in placing all k mailboxes
            if(k == 0) return 0;
            return 1e9;
        }
        
        // if k becomes 0 before exhausting all houses then don't go further
        if(k == 0) return 1e9;
        
        // dp check
        if(dp[index][k]!=-1) return dp[index][k];
        
        // place a mailbox b/w house in current index and some houses upcoming
        int ans = 1e9;
        for(int j=index; j<n; j++){
            // allocate the mailbox in the median of [index...j] so that cost is minimum
            int medianIndex = (index + j) / 2;
            int cost = 0;
            for(int p=index; p<=j; p++){
                cost += abs(houses[p]-houses[medianIndex]);
            }
            
            // now carry forward this cost and find for next houses
            ans = min(ans, cost + solve(j+1, k-1, n, houses));
        }
        return dp[index][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        // sort the houses, as we assume houses will be sorted, this logic will work only if sorted
        // since median is involved
        sort(begin(houses), end(houses));
        // memoization:
        memset(dp, -1, sizeof(dp));
        return solve(0, k, n, houses);
    }
};