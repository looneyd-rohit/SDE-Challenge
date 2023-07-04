// Leetcode 2749
class Solution {
public:
    int countBits(long long n){
        int cnt = 0 ;
        for(int i=0; i<61; i++){
            if(n & (1LL<<i)){
                cnt++;
            }
        }
        return cnt;
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 < num2) return -1;
        for(int k=0; k<61; k++){
            int bits = countBits(1LL*num1-1LL*k*num2);
            if(k <= (1LL*num1-1LL*k*num2) && bits <= k){
                return k;
            }
        }
        return -1;
    }
};