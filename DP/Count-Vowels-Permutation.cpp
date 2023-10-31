// Leetcode 1220

class Solution {
public:
    const int M = 1e9+7;
    int dp[(int)2e4+1][26];
    int solve(int index, char prev, int n, unordered_map<char, list<char>>& adj){
        // base case
        if(index == n){
            return 1;
        }

        // dp check
        if(dp[index][prev-'a']!=-1) return dp[index][prev-'a'];

        int ans = 0;
        for(auto& ch: adj[prev]){
            ans += solve(index+1, ch, n, adj) % M;
            ans %= M;
        }
        return dp[index][prev-'a'] = ans;
    }
    void init(unordered_map<char, list<char>>& adj){
        adj['a'].push_back('e');
        adj['e'].push_back('a');
        adj['e'].push_back('i');
        adj['i'].push_back('a');
        adj['i'].push_back('e');
        adj['i'].push_back('o');
        adj['i'].push_back('u');
        adj['o'].push_back('i');
        adj['o'].push_back('u');
        adj['u'].push_back('a');
        adj['z'].push_back('a');
        adj['z'].push_back('e');
        adj['z'].push_back('i');
        adj['z'].push_back('o');
        adj['z'].push_back('u');
    }
    int countVowelPermutation(int n) {
        unordered_map<char, list<char>> adj;
        init(adj);
        memset(dp, -1, sizeof(dp));
        return solve(0, 'z', n, adj);
    }
};