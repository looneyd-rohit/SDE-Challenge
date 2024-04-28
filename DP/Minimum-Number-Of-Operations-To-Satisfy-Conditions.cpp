// Leetcode 3122

// Approach 1: simple dp + precomputation
class Solution {
public:
    int store[1001][11];
    int solve(int i, int j, int n, vector<vector<int>>& dp){
        if(i == n) return 0;
        if(store[i][j+1]!=-1) return store[i][j+1];
        int ans = 1e9;
        for(int col=0; col<10; col++){
            if(col!=j){
                ans = min(ans, dp[i][col] + solve(i+1, col, n, dp));
            }
        }
        return store[i][j+1] = ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(10, 0));
        memset(store, -1, sizeof(store));
        for(int num=0; num<=9; num++){
            for(int j=0; j<n; j++){
                int count = 0;
                for(int i=0; i<m; i++){
                    if(grid[i][j]!=num){
                        count++;
                    }
                }
                dp[j][num] = count;
            }
        }
        return solve(0, -1, n, dp);
    }
};

// Approach 2: optimized dp for larger constraints taking only top 3 elements as those will be sufficient to compute the minimum operations
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> store;
    long long solve(int index, int last, int n, int m, vector<vector<pair<int, int>>>& dp){
        if(index == n) return 0;

        if(store.find(index)!=store.end()){
            if(store[index].find(last)!=store[index].end()){
                return store[index][last];
            }
        }
        // traverse all possible values except the last
        long long ans = 1e18;
        for(auto& p: dp[index]){
            if(p.second != last){
                ans = min(ans, m - p.first + solve(index+1, p.second, n, m, dp));
            }
        }
        return store[index][last] = ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // alternate approach: works for even larger array sizes and larger limits
        // of values => more optimized by some precomputation
        // for each index, we see that only at max 3 distinct values need to be
        // tested those being: the highest frequency element, the second highest frequency
        // element and the third highest frequency element, for each column
        unordered_map<int, unordered_map<int, int>> freq;
        vector<vector<pair<int, int>>> dp(n);
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                int e = grid[i][j];
                freq[j][e]++;
            }
            // take only the max 3 frequencies
            vector<pair<int, int>> temp;
            for(auto& e: freq[j]){
                temp.push_back({e.second, e.first});
            }
            sort(rbegin(temp), rend(temp));
            for(int i=0; i<temp.size(); i++){
                dp[j].push_back(temp[i]);
                if(dp[j].size() == 3) break;
            }
            while(dp[j].size() < 3){
                int a = 1e9, b = 0;
                // a -> dummy element, b -> dummy frequency
                dp[j].push_back({b, a++});
            }
        }
        return solve(0, -1, n, m, dp);
    }
};