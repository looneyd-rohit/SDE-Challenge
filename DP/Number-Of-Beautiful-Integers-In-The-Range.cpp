// Leetcode 2827

class Solution {
public:
    int dp[15][2][2][15][15][25];
    int solve(int len, string& str, bool tight, bool isZero, int evens, int odds, int k, int rem){
        // base case
        if(len == 0){
            return (!isZero) && (rem == 0) && (evens == odds);
        }
        
        // dp check
        if(dp[len][tight][isZero][evens][odds][rem]!=-1) return dp[len][tight][isZero][evens][odds][rem];
        
        
        int ub = tight ? str[str.length() - len] - '0' : 9;

        int ans = 0;
        for (int digit = 0; digit <= ub; digit++)
        {
            if(isZero){
                if(digit == 0){
                    ans += solve(len-1, str, tight & (digit == ub), true, evens, odds, k, (rem*10+digit)%k);
                }else{
                    if(digit%2 == 0) evens++;
                    else odds++;
                    ans += solve(len-1, str, tight & (digit == ub), false, evens, odds, k, (rem*10+digit)%k);
                    if(digit%2 == 0) evens--;
                    else odds--;
                }
            }else{
                if(digit%2 == 0) evens++;
                else odds++;
                ans += solve(len-1, str, tight & (digit == ub), false, evens, odds, k, (rem*10+digit)%k);
                if(digit%2 == 0) evens--;
                else odds--;
            }
        }
        return dp[len][tight][isZero][evens][odds][rem] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l = to_string(low-1);
        string h = to_string(high);
        memset(dp, -1, sizeof(dp));
        int hh = solve(h.length(),h,1,1,0,0,k,0);
        memset(dp, -1, sizeof(dp));
        int ll = solve(l.length(),l,1,1,0,0,k,0);
        return (hh-ll); 
    }
};