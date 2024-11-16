// Leetcode 3116

// Approach: classic inclusion exclusion principle logic
class Solution {

    int64_t gcd(int64_t a, int64_t b) {
	    return (b == 0 ? a : gcd(b, a % b));
    }
    
    int64_t lcm(int64_t a, int64_t b) {
        return a / gcd(a, b) * b;
    }

    // Count the numbers of integers smaller or equal to x 
    // without duplicates.
    int64_t count(vector<int>& coins, int64_t x) {
        int size = coins.size();
        int64_t sum = 0;
        for (int mask = 1; mask < (1 << size); mask++) {
            // number of bits set on
            int bits = __builtin_popcountll(mask);  
            int64_t leastComMul = 1; 
            for (int j = 0; j < size; j++) {
                if (mask & (1 << j))
                    leastComMul = lcm(leastComMul, coins[j]); //get the lcm for the subset
            }
            if (bits & 1) // if is odd add otherwise subtract
                sum += x / leastComMul;
            else
                sum -= x / leastComMul;
        }
        return sum;
    }

    int64_t binarySearch(vector<int>& coins, int64_t k) {
        int64_t left = 1, right = 25LL * 2e9;
        while (left < right) {
            int64_t mid = left + (right - left) / 2;
            if (count(coins, mid) < k)
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }
    
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        return binarySearch(coins, k);
    }
};