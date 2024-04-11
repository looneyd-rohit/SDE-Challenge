// Leetcode 678

// Approach: simple dp maintaining bracket differences, capturing all possibilities
class Solution {
public:
    int dp[101][101];
    bool solve(int index, int diff, string& s){
        if(index >= s.length()) return (diff==0);
        if(diff < 0) return false;

        if(dp[index][diff]!=-1) return dp[index][diff];

        if(s[index] == '(') return dp[index][diff] = solve(index+1, diff+1, s);
        else if(s[index] == ')') return dp[index][diff] = solve(index+1, diff-1, s);
        else{
            return dp[index][diff] = (solve(index+1, diff, s) || solve(index+1, diff+1, s) || solve(index+1, diff-1, s));
        }
    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s);
    }
};