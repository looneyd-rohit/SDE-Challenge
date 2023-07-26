// Leetcode 1434
// DP + Bitmasking

// Approach 1: Distributing hats to persons
class Solution {
public:
    const int M = 1e9+7;
    long long solve(int index, long long mask, int n, vector<vector<int>>& hats){
        // base case
        if(index >= hats.size()) return 1;
        
        // mask --> current hats worn
        // for the current person allocate a hat if possible
        long long ans = 0;
        for(auto hat: hats[index]){
            if(mask & (1LL<<hat)){
                // hat already allocated
            }else{
                // not allocated
                ans += solve(index+1, mask | (1LL<<hat), n, hats) % M;
                ans %= M;
            }
        }
        return ans % M;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        // we can't memoize it since here we are distributing hats to persons, so mask
        // represents hats allocated, and it can go as large as 2^40 which is not favourable
        // for memory
        return solve(0, 0, n, hats);
    }
};


// Approach 2: Distributing persons to hats (reverse)
class Solution {
public:
    const int M = 1e9+7;
    int dp[41][(1<<10)+1];
    long long solve(int index, long long mask, int hatCount, int totalPersons, vector<int>& uniqueHats, vector<int>& hatToPersonMap){
        // base case
        if(index >= hatCount){
            // all persons got something
            if(mask == (1LL<<totalPersons)-1) return 1;
            // not enough hats to distribute
            return 0;
        }
        
        // dp check
        if(dp[index][mask]!=-1) return dp[index][mask];
        
        // mask --> current persons allocated hats
        long long ans = solve(index+1, mask, hatCount, totalPersons, uniqueHats, hatToPersonMap);    // don't distribute this hat
        
        // distribute the current hat to some person
        int hatNumber = uniqueHats[index];
        
        for(int person=0; person<totalPersons; person++){
            if(hatToPersonMap[hatNumber] & (1LL<<person)){
                if(mask & (1LL<<person)){
                    
                }else{
                    ans += solve(index+1, mask | (1LL<<person), hatCount, totalPersons, uniqueHats, hatToPersonMap) % M;
                    ans %= M;
                }
            }
            
        }
        return dp[index][mask] = ans % M;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        // we need unique hat numbers and their count
        unordered_set<int> uniqueHatsSet;
        // we need to hat to person mapping in O(1) so use another map/set
        vector<int> hatToPersonMap(41, 0);
        for(int i=0; i<n; i++){
            for(auto& hat: hats[i]){
                 uniqueHatsSet.insert(hat);
                hatToPersonMap[hat] |= (1LL<<i);
            }
        }
        vector<int> uniqueHats(uniqueHatsSet.begin(), uniqueHatsSet.end());
        int hatCount = uniqueHats.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, hatCount, n, uniqueHats, hatToPersonMap);
    }
};