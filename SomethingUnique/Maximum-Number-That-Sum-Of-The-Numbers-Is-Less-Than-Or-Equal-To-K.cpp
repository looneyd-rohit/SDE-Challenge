// Leetcode 3007

// [IMP] Approach: bit counting approach of numbers from 1 to num, using f(num, i) and g(num) khandani approach
class Solution {
public:
    unsigned long long f(unsigned long long x, unsigned long long i){
        unsigned long long a = (x + 1) / (1LL << (i + 1));
        a = a * (1LL << i);

        long long excess = ((x + 1) % (1LL << (i + 1))) - (1LL << i);

        return a + max(0LL, excess);
    }
    bool g(unsigned long long num, unsigned long long k, int x){
        unsigned long long sum = 0;
        for(int i=x; i<63; i+=x){
            unsigned long long t = f(num, i-1);
            sum += t;
        }
        return (sum <= k);
    }
    long long findMaximumNumber(long long k, int x) {
        unsigned long long low = 1, high = 1e18;
        while(low <= high){
            unsigned long long mid = low + ((high - low) >> 1);
            if(g(mid, k, x)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return high;
    }
};