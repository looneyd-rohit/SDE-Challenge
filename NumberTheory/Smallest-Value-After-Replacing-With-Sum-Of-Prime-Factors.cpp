// Leetcode 2507
// [IMP]: Sieve Pattern with lprimes and hprimes

class Solution {
public:
    int primeFactorsSum(int n, vector<int>& lprimes){
        int sum = 0;
        while(n > 1){
            int lowPrime = lprimes[n];
            while(n % lowPrime == 0){
                sum += lowPrime;
                n /= lowPrime;
            }
        }
        return sum;
    }
    int smallestValue(int n) {
        vector<int> primes, lprimes, hprimes;
        primes.resize(n+1, 1);
        lprimes.resize(n+1, -1);
        hprimes.resize(n+1, -1);
        primes[0] = primes[1] = 0;
        for(int i=2; i<=n; i++) lprimes[i] = i, hprimes[i] = i;
        for(int i=2; i*i<=n; i++){
            if(primes[i]){
                // for prime no. i, lprimes = hprimes = i
                lprimes[i] = hprimes[i] = i;
                for(int j=i*i; j<=n; j+=i){
                    primes[j] = false;
                    // update lprimes only once
                    lprimes[j] = min(lprimes[i], i);
                    // update hprimes everytime as larger it gets
                    hprimes[j] = i;
                }
            }
        }
        if(primes[n]) return n;
        // for(auto& e: lprimes) cout<<e<<" ";cout<<endl;
        while(true){
            int sumOfPrimeFactors = primeFactorsSum(n, lprimes);
            if(sumOfPrimeFactors == n) break;
            n = sumOfPrimeFactors;
        }
        return n;
    }
};