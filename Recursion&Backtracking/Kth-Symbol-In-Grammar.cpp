// Leetcode 779

class Solution {
public:
    int solve(int n, int k){
        if(n==0) return 0;
        if(n==1) return (k==1);

        int mid = pow(2, n) / 2;

        if(k < mid) return solve(n-1, k);
        else return 1 - solve(n-1, k % mid);
    }
    int kthGrammar(int n, int k) {
        return solve(n-1, k-1);
    }
};