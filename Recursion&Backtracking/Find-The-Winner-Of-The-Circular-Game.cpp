// Leetcode 1823

class Solution {
public:
    int solve(int n, int k){
        if(n==1) return 0;
        int winner = solve(n-1, k) + k;
        return winner % n;
    }
    int findTheWinner(int n, int k) {
        return solve(n, k) + 1;
    }
};