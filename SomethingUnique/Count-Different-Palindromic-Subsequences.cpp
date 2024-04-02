// Leetcode 730

// [IMP] Approach: dp + distinct palindromic check using derivations
class Solution {
public:
    const int M = 1e9+7;
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        // we need the next and previous occurences to be stored
        vector<int> hash(26, -1);
        vector<int> prev(n, -1);
        for(int i=0; i<n; i++){
            prev[i] = hash[s[i]-'a'];
            hash[s[i]-'a'] = i;
        }
        hash.resize(26, n);
        vector<int> next(n, -1);
        for(int i=n-1; i>=0; i--){
            next[i] = hash[s[i]-'a'];
            hash[s[i]-'a'] = i;
        }
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int i=0, j=1; i<n && j<n; i++, j++) dp[i][j] = 2;
        for(int gap=2; gap<n; gap++){
            for(int i=0, j=gap; i<n && j<n; i++, j++){
                if(s[i]==s[j]){
                    int n_ind = next[i], p_ind = prev[j];
                    if(n_ind > p_ind){
                        // no occurence in between
                        dp[i][j] = (2*dp[i+1][j-1] + 2) % M;
                    }else if(n_ind == p_ind){
                        // 1 occurence in between
                        dp[i][j] = (2*dp[i+1][j-1] + 1) % M;
                    }else{
                        // more than one occurence in between
                        dp[i][j] = (2*dp[i+1][j-1] - dp[n_ind+1][p_ind-1] + M) % M;
                    }
                }else{
                    int a = dp[i][j-1];
                    int b = dp[i+1][j];
                    int c = dp[i+1][j-1];
                    dp[i][j] = ((a + b) % M - c + M) % M;
                }
            }
        }
        return dp[0][n-1] % M;
    }
};