// Leetcode 2485

class Solution {
public:
    int pivotInteger(int n) {
        // [1...x] --> x * (x+1) / 2
        // [x...n] --> n * (n+1) / 2 - (x-1) * x / 2
        double ans = sqrt((pow(n, 2) + n) / 2);
        int k = ans;
        if(k == ans) return k;
        return -1;
    }
};