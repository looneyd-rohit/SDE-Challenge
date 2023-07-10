// Leetcode 1390


class Solution {
public:
    pair<int, int> findTotalPrimeDivisors(int n, vector<int>& lprimes){
        unordered_map<int, int> umap;
        while(n > 1){
            int lowprime = lprimes[n];
            while(n % lowprime == 0){
                umap[lowprime]++;
                n /= lowprime;
            }
        }
        int total = 1;
        int sum = 1;
        for(auto& e: umap){
            // cout<<e.first<<" "<<e.second<<endl;
            total *= (e.second+1);
            sum *= (pow(e.first, e.second+1)-1)/(e.first - 1);
        }
        return {total, sum};
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        vector<int> primes, lprimes, hprimes;
        primes.resize(maxi+1, 1);
        lprimes.resize(maxi+1, -1);
        hprimes.resize(maxi+1, -1);
        primes[0] = primes[1] = false;
        for(int i=2; i<=maxi; i++) lprimes[i] = hprimes[i] = i;
        for(int i=2; i*i<=maxi; i++){
            if(primes[i]){
                for(int j=i*i; j<=maxi; j+=i){
                    primes[j] = false;
                    lprimes[j] = min(lprimes[j], i);
                    hprimes[j] = max(hprimes[j], i);
                }
            }
        }
        // now that we have all primes computed that we may require
        // time to calculate divisors for each number
        unordered_map<int, int> divisorSums;
        int totalSum = 0;
        for(int i=0; i<n; i++){
            if(divisorSums.find(nums[i]) != divisorSums.end()){
                totalSum += divisorSums[nums[i]];
                continue;
            }
            auto p = findTotalPrimeDivisors(nums[i], lprimes);
            int total = p.first, sum = p.second;
            // cout<<nums[i]<<" "<<total<<" "<<sum<<endl;
            if(total == 4){
                divisorSums[nums[i]] = sum;
                totalSum += sum;
            }
        }
        return totalSum;
    }
};