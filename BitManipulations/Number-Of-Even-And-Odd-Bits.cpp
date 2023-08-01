// Leetcode 2595

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        for(int i=0; i<31; i++){
            if(i & 1){
                // odd
                if(n & (1<<i)){
                    odd++;
                }
            }else{
                // even
                if(n & (1<<i)){
                    even++;
                }
            }
        }
        return {even, odd};
    }
};