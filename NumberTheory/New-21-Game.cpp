// Leetcode 837
// One of the hardest in entire leetcode

// Approach 1: Brute Force
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // APPROACH: BRUTE FORCE
        // edge cases
        if(k == 0) return 1;    // we can never make any score and hence <=n always
        if(k-1+maxPts<n) return 1;    // we can never make any score larger than k-1_maxPts

        vector<double> probability(n+1, 0);
        probability[0] = 1.0;
        for(int i=1; i<=n; i++){
            for(int card=1; card<=maxPts; card++){
                if((i - card) >= 0 && (i - card) < k){
                    // very closely look at the condition given it is very difficult
                    probability[i] += probability[i-card] * (1.0 / maxPts);
                }
            }
        }

        double ans = 0;
        for(int i=k; i<=n; i++){
            ans += probability[i];
        }

        return ans;
    }
};

// Approach 2: Sliding Window + DP + Probability
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // APPROACH: BRUTE FORCE
        // edge cases
        if(k == 0) return 1;    // we can never make any score and hence <=n always
        if(k-1+maxPts<n) return 1;    // we can never make any score larger than k-1_maxPts

        vector<double> probability(n+1, 0);
        probability[0] = 1.0;
        // instead of recomputing the probability every time we can make a sliding window
        double currProbSum = 1.0;
        for(int i=1; i<=n; i++){
            probability[i] = currProbSum / maxPts;

            // expand the window till k (exclusive)
            if(i < k) currProbSum += probability[i];

            // shrink the left boundary
            if((i - maxPts) >= 0 && (i - maxPts) < k) currProbSum -= probability[i-maxPts];
        }

        double ans = 0;
        for(int i=k; i<=n; i++){
            ans += probability[i];
        }

        return ans;
    }
};