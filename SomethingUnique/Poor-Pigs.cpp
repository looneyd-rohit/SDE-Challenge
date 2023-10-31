// Leetcode 458

class Solution {
public:
    int solve(long long buckets, long long trials){
        long long x = 1;
        long long t = trials;
        while(t < buckets){
            t = t * trials;
            x++;
        }
        return x;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1) return 0;
        int trials = minutesToTest / minutesToDie;
        // return solve(buckets, trials+1);
        // one liner
        return ceil(log2(buckets) / log2(trials+1));
    }
};