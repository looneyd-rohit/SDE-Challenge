// Leetcode 878
// Maths + Binary Search (LCM, HCF/GCD based)

class Solution {
public:
    const int M = 1e9+7;
    long long gcd(long long a, long long b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    long long lcm(long long a, long long b){
        long long pdt = (a * b);
        return pdt / gcd(a, b);
    }
    long long calculate(unsigned long long n, long long a, long long b, long long l){
        unsigned long long p = n / a;
        unsigned long long q = n / b;
        unsigned long long r = n / l;
        return (p + q - r);
    }
    int nthMagicalNumber(int n, int a, int b) {
        // n-th number to be divisible by either a or b
        unsigned long long low = 1, high = min(a, b) * 1ULL* n;
        long long l = lcm(a, b);
        while(low <= high){
            unsigned long long mid = low + ((high - low) >> 1);
            unsigned long long divisors = calculate(mid, a, b, l);
            if(divisors >= n){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low % M;
    }
};