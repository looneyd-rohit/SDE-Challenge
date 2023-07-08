// Leetcode 2746
// [IMP]: Knapsack (0/1) based DP

class Solution {
public:
    int solve(int index, char start, char end, vector<string>& words, vector<vector<vector<int>>>& dp){
        // base case
        if(index >= words.size()) return 0;

        // dp check
        if(dp[index][start-'a'][end-'a']!=-1) return dp[index][start-'a'][end-'a'];

        // join [start...end] + words[index]
        int joinFirst = words[index].length() - (end == words[index].front()) + solve(index+1, start, words[index].back(), words, dp);

        // join  words[index] + [start...end]
        int joinSecond = words[index].length() - (words[index].back() == start) + solve(index+1, words[index].front(), end, words, dp);

        return dp[index][start-'a'][end-'a'] = min(joinFirst, joinSecond);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        // knapsack pattern dp --> nice question, slightly intuitive
        // we are only concerned about the start and end characters of a string, hence
        // we only store them only
        int n = words.size();
        // memoization:
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(26, vector<int>(26, -1)));
        return words[0].size() + solve(1, words[0].front(), words[0].back(), words, dp);
    }
};