// Leetcode 50

class Solution {
public:
    double solve(double x, long n){
        if(n == 0) return 1;

        if(n & 1){
            return x * solve(x, n-1);
        }

        return solve(x*x, n/2);
    }
    double myPow(double x, int n) {
        double temp = n;
        if(temp < 0) temp = -temp;
        double ans = solve(x, temp);
        if(n < 0) return 1 / ans;
        return ans;
    }
};