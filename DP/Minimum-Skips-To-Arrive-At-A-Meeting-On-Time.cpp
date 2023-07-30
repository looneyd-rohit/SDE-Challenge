// Leetcode 1883
// [IMP]: DP pattern where state variable itself if the answer
// we iterate for different values of state variable calling solve() / dp()
// and find the optimal state variable which satisfies

class Solution {
public:
    double dp[1001][1001];
    double solve(int index, int skips, vector<int>& dist, double speed, int hoursBefore){
        // base case
        if(index < 0){
            return 0;
        }
        
        // dp check
        if(dp[index][skips]!=0.0) return dp[index][skips];

        // skip 
        double skip = 1e9;
        if(skips > 0) skip = (dist[index] / speed) + solve(index-1, skips-1, dist, speed, hoursBefore);

        // don't skip
        double dontSkip = solve(index-1, skips, dist, speed, hoursBefore);
        int dontSkipInt = dontSkip;

        if(dontSkip - dontSkipInt >= 1e-6){
            // decimal part exists, take rest in that part, no skip
            dontSkip = dontSkipInt + 1 + (dist[index] / speed);
        }else{
            // int and double same, hence
            // no rest, no skip
            dontSkip += (dist[index] / speed);
        }

        return dp[index][skips] = min(skip, dontSkip);
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        long long total = 0;
        for(auto& e: dist) total += e;
        if((total * 1.0) / speed > hoursBefore) return -1;
        // define solve(ind, skips) --> which returns min time to reach ind
        // starting from 0 with skips no. of skipping available
        // memoization:
        memset(dp, 0.0, sizeof(dp));
        for(int i=0; i<n; i++){
            double t = solve(n-1, i, dist, 1.0*speed, hoursBefore);
            // cout<<t<<endl;
            if(t <= hoursBefore){
                return i;
            }
        }
        return -1;
    }
};