// Leetcode 1871

// [IMP] Approach 1: using sliding window
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s.back()=='1') return false;
        for(int i=0, j=0; i<n; i++){
            if(i==0 || s[i]=='2'){
                for(j=max(j, i+minJump); j<=min((int)s.length()-1, i+maxJump); j++){
                    if(s[j]=='0'){
                        s[j] = '2';
                    }
                }
            }
        }
        return s.back() == '2';
    }
};

// [IMP] Approach 2: using dp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump)
                pre += dp[i - minJump];
            if (i > maxJump)
                pre -= dp[i - maxJump - 1];
            dp[i] = pre > 0 && (s[i] == '0');
        }
        return dp[n - 1];
    }
};