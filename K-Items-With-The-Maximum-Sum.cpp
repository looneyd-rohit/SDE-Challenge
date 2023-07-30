// Leetcode 2600

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int n1 = min(k, numOnes);
        int n2 = min(k-n1 >= 0 ? k-n1 : 0, numZeros);
        int n3 = min(k-n2-n1 >=0 ? k-n2-n1 : 0, numNegOnes);
        return n1 - n3;
    }
};