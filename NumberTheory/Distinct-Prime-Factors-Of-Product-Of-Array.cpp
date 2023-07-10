// Leetcode 2521
// [IMP]: Sieve with lprimes hprimes pattern

class Solution {
public:
    void findPrimeFactors(int n, vector<int>& lprimes, vector<int>& distinctPrimes){
        while(n > 1){
            int lowprime = lprimes[n];
            while(n % lowprime == 0){
                distinctPrimes[lowprime] = 1;
                n /= lowprime;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        for(int i=1; i<n; i++) maxi=max(maxi, nums[i]);
        
        // now generate all primes less than maxi
        vector<int> primes, lprimes, hprimes;
        primes.resize(maxi+1, 1);
        lprimes.resize(maxi+1, -1);
        hprimes.resize(maxi+1, -1);
        primes[0] = primes[1] = 0;
        for(int i=2; i<=maxi; i++) lprimes[i] = i, hprimes[i] = i;
        for(int i=2; i*i<=maxi; i++){
            if(primes[i]){
                lprimes[i] = hprimes[i] = i;
                for(int j=i*i; j<=maxi; j+=i){
                    primes[j] = false;
                    lprimes[j] = min(lprimes[j], i);
                    hprimes[j] = max(hprimes[j], i);
                }
            }
        }

        // now that we have all the lowprimes of a number we can get all distinct
        // prime factors
        vector<int> distinctPrimes(maxi+1, 0);
        for(int i=0; i<n; i++){
            int num = nums[i];
            findPrimeFactors(num, lprimes, distinctPrimes);
        }

        int ans = 0;
        for(int i=0; i<distinctPrimes.size(); i++){
            if(distinctPrimes[i]) ans++;
        }
        return ans;
    }
};