// Leetcode 3101

// Approach: khandani sliding window template
class Solution {
   public:
    long long countAlternatingSubarrays(vector<int>& A) {
        long long n = A.size(), i = 0, j = 0, p = -1, c = 0;
        while (j < n) {
            long long el = A[j];
            if ((p > el) || (p < el)) {
                c += (j - i + 1);
                j++;
            } else {
                i = j;
                c++;
                j++;
            }
            p = el;
        }
        return c;
    }
};