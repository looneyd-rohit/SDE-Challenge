// Leetcode 3091

// Approach: binary search + read comments
class Solution {
public:
    bool isPossible(int k, int mid){
        // initially nums = [1]
        // if we observe carefully we see that it is optimal to
        // increase the values at first and then duplicate so that
        // less duplications result in sum k
        // x -> increase ops -> 1 becomes 1+x
        // y -> duplicate ops -> 1+x becomes y(1+x)
        // (1+y)(1+x) >= k
        // also x + y = mid (here)
        // substitute -> (1+mid-x)(1+x) >= k
        // this is a graph of parabola (inverted), now for this to have some value >= 0
        // this should have determinant (D) >= 0 otherwise it will always have negative value
        return pow(mid+2, 2) >= 4*k;
    }
    int minOperations(int k) {
        // operations can be in the range 0....infinity
        int low = 0, high = 1e5;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossible(k, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};