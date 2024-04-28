// Leetcode 3116

// Approach: classic inclusion exclusion principle logic
class Solution {
public:
    long long gcd(long long a, long long b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    long long computeLCM(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }
    bool isPossible(vector<long long>& lcm, int n, long long mid, long long k){
        unsigned long long sum = 0;
        for(int i=1; i<(1<<n); i++){
            int cnt = __builtin_popcount(i);
            int e = lcm[i];
            if(cnt & 1) sum += mid / e;
            else sum -= mid / e;
        }
        return (sum >= k);
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        sort(begin(coins), end(coins));
        // classic problem of inclusion - exclusion principle
        // calculate all the subsets of coins
        vector<long long> lcm((1<<n), 1);
        for(int sub=0; sub<(1<<n); sub++){
            for(int bit=0; bit<n; bit++){
                if(sub & (1<<bit)){
                    lcm[sub] = computeLCM(lcm[sub], coins[bit]);
                }
            }
        }
        long long low = 1, high = 1e11;
        while(low <= high){
            long long mid = low + ((high - low) >> 1);
            if(isPossible(lcm, n, mid, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};