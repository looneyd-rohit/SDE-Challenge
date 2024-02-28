// Leetcode 1561

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles), end(piles));
        int i=0, j=n-1;
        int bob=0, me=0, alice=0;
        while(i<j-1){
            bob += piles[i++];
            alice += piles[j--];
            me += piles[j--];
        }
        return me;
    }
};