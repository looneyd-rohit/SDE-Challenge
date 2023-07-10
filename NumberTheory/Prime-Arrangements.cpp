// Leetcode 1175

class Solution {
public:
    const int M = 1e9+7;
    int fact(int n){
        long long ans = 1;
        while(n > 1){
            ans = ans * n;
            ans = ans % M;
            n--;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        // typical sieve problem --> all primes are at prime indices
        vector<int> primes;
        primes.resize(n+1, 1);
        primes[0] = primes[1] = false;
        for(int i=2; i*i<=n; i++){
            if(primes[i]){
                for(int j=i*i; j<=n; j+=i){
                    primes[j] = false;
                }
            }
        }
        int count = 0;    // count of primes at prime indices
        for(int i=0; i<=n; i++) count += primes[i];

        // now that we have the primes from 1 to n, we can perform the combinations
        int one = fact(n-count);
        int two = fact(count);
        return (1LL * one * two) % M;
    }
};