// Leetcode 3099

// Approach: brute force
class Solution {
   public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        if (temp % sum == 0) return sum;
        return -1;
    }
};