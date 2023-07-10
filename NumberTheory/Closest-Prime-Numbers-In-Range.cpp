// Leetcode 2523
// [IMP]: Segmented Sieve Approach

class Solution {
public:
    vector<bool> primes;
    Solution(){
        primes.resize(1e6+1, true);
        primes[0] = primes[1] = false;
        for(int i=2; i*i<=1e6; i++){
            if(primes[i]){
                for(int j=i*i; j<=1e6; j+=i){
                    primes[j] = false;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        // range based primes --> segmented sieve
        vector<int> reqPrimes;
        int num = floor(sqrt(right));
        for(int i=0; i<=num; i++){
            if(this->primes[i]){
                reqPrimes.push_back(i);
            }
        }

        // iterate over all the primes between [2...sqrt(r)]
        vector<int> finalPrimes(right-left+1, true);
        if(left <= 1){
            int temp = left;
            while(temp--) finalPrimes[temp] = false;
        }
        for(auto& prime: reqPrimes){
            int firstMultiple = (left / prime) * prime;
            if(firstMultiple < left) firstMultiple += prime;
            for(int j=max(firstMultiple, prime*prime); j<=right; j+=prime){
                // mark all the multiples of prime as false
                finalPrimes[j-left] = false;
            }
        }

        // now that i have the final primes, I can get the pairs as required
        int first = -1, second = -1;
        int finalFirst = -1, finalSecond = -1;
        int mini = INT_MAX;
        for(int i=left; i<=right; i++){
            if(finalPrimes[i-left]){
                second = i;
                if(first != -1){
                    int diff = second - first;
                    if(diff < mini){
                        mini = diff;
                        finalFirst = first;
                        finalSecond = second;
                    }
                }
            }
            first = second;
        }
        return {finalFirst, finalSecond};
    }
};