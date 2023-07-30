// Leetcode 808

class Solution {
public:
    vector<pair<int, int>> moves = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
    double dp[201][201] = {0.0};
    double solve(int n1, int n2){
        // base case
        if(n1 == 0 || n2 == 0){
            if(n1 == 0 && n2 != 0) return 1;
            if(n1 == 0 && n2 == 0) return (1.0 / 2);
            return 0;
        }

        if(dp[n1][n2]!=0.0) return dp[n1][n2];

        double prob = 0;
        // cout<<n1<<" and "<<n2<<endl;
        for(auto& move: moves){
            int dx = min(move.first, n1), dy = min(move.second, n2);
            double p = solve(n1-dx, n2-dy);
            // cout<<dy<<", "<<dy<<" has "<<p<<endl;
            prob += 0.25 * p;
        }
        return dp[n1][n2] = prob;
    }
    double soupServings(int n) {
        if(n == 0) return 0.5;
        int new_n = ceil((n * 1.0) / 25);
        for(int m=1; m<=new_n; m++){
            if(solve(m, m) > 1-1e-5){
                return 1;
            }
        }
        return solve(new_n, new_n);
    }
};