// Leetcode 2338

class Solution {
public:
    const int M = 1e9+7;
    vector<vector<int>> chainLengths;
    vector<vector<int>> dpArrangements;
    void getLengthsOfDivisorForANumber(int maxValue){
        chainLengths.resize(1e4+1, vector<int>(16, 0));
        
        for(int i=1; i<=maxValue; i++){
            chainLengths[i][1] = 1;
            for(int j=2*i; j<=maxValue; j+=i){
                // for all multiples of i
                // also max length of chain can be 14 so
                for(int chainLen=1; chainLen<=14; chainLen++){
                    // we move from chainLen = 1 since 0 len won't be required already covered
                    chainLengths[j][chainLen+1] += chainLengths[i][chainLen];
                }
            }
        }
    }
    int findUniqueArrangementsForKDivisors(int index, int length, int divisorCount){
        // we return 1 only when all the divisors are used up, if all divisors aren't used
        // up then, we are not utitilising all the divisors as said
        if(index >= length) return (divisorCount == 0);
        if(divisorCount == 0) return 0;
        
        // dp check
        if(dpArrangements[index][divisorCount]!=-1) return dpArrangements[index][divisorCount];
        
        // put one divisor on current index
        
        // call for next index with same divisors
        int a = findUniqueArrangementsForKDivisors(index+1, length, divisorCount);
        
        // call for next index with other divisors
        int b = findUniqueArrangementsForKDivisors(index+1, length, divisorCount-1);
        
        return dpArrangements[index][divisorCount] = (a + b) % M;
    }
    int idealArrays(int n, int maxValue) {
        // elements don't matter only their count matters, since arrangements for a
        // set of ideal array digits like [1, 2, 4] and [1, 2, 10] will be same always
        
        // compute the chainLengths for each number from 1 to maxValue
        getLengthsOfDivisorForANumber(maxValue);
        // cout<<"computed"<<endl;
        
        dpArrangements.resize(1e4+1, vector<int>(16, -1));
        long long ans = 0;
        for(int num=1; num<=maxValue; num++){
            for(int chainLen=1; chainLen<=14; chainLen++){
                long long arrangements = findUniqueArrangementsForKDivisors(0, n, chainLen);
                
                // one or more chains of same length may exists, so
                ans = (ans + (arrangements * chainLengths[num][chainLen]) % M) % M;
                ans %= M;
            }
        }
        return ans;
    }
};