// Leetcode 342

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        bool isPowerOf2 = !(n & (n - 1));
        if(isPowerOf2){
            int k = __builtin_popcount(n-1);
            if(k % 2 == 0) return true;
        }
        return false;
    }
};