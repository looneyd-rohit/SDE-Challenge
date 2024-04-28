// Leetcode 2370

// Approach: dp + lis bottom up variant
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(n, 1);
        vector<int> store(26, 0);
        for(int i=0; i<n; i++){
            char ch = s[i];
            for(int t=-k; t<=k; t++){
                char ch2 = ch + t;
                if(ch2>='a' && ch2<='z'){
                    if(store[ch2-'a'] + 1 > dp[i]){
                        dp[i] = store[ch2-'a'] + 1;
                    }
                }
            }
            store[ch-'a'] = dp[i];
        }
        return *max_element(begin(dp), end(dp));
    }
};