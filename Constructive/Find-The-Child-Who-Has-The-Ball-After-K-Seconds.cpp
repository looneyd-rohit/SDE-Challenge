// Leetcode 3178

// Approach: constructive
class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycleLength = calculateCycleLength(n);
        int kMod = calculateKMod(k, cycleLength);
        
        return computeResult(n, kMod);
    }

public:
    int calculateCycleLength(int n) {
        return 2 * (n - 1);
    }

    int calculateKMod(int k, int cycleLength) {
        return k % cycleLength;
    }

    int computeResult(int n, int kMod) {
        if (kMod < n) {
            return kMod;
        } else {
            return 2 * (n - 1) - kMod;
        }
    }
};
