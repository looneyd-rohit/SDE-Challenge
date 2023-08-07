// Leetcode 139

class Solution {
public:
    int dp[301];
    bool solve(int index, int n, string& s, unordered_set<string>& hash){
        // base case
        if(index >= n) return true;

        // dp check
        if(dp[index]!=-1) return dp[index];

        bool ans = false;
        for(int i=index; i<n; i++){
            string str = s.substr(index, i-index+1);
            if(hash.count(str)){
                ans = ans | solve(i+1, n, s, hash);
            }
        }
        return dp[index] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> hash;
        for(auto& word: wordDict) hash.insert(word);
        memset(dp, -1, sizeof(dp));
        return solve(0, n, s, hash);
    }
};