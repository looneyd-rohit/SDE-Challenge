// Leetcode 3100

// Approach: loop until empty cannot be converted
class Solution {
   public:
    int maxBottlesDrunk(int numBottles, int n) {
        int t = numBottles, e = 0, m = 0;
        while (t > 0) {
            m += t;
            e += t;
            t = 0;
            if (e >= n) {
                t = 1;
                e -= n;
                n += 1;
            } else
                break;
        }
        return m;
    }
};