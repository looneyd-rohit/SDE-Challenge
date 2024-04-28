// Leetcode 3133

// [IMP] Approach: bit manipulations
class Solution {
public:
    int largest(int x){
        int maxi = -1;
        for(int i=0; i<30; i++){
            if(x & (1<<i)){
                maxi = i;
            }
        }
        return maxi;
    }
    long long find_start(int x, int k){
        long long req = x;
        for(int i=0, j=0; i<64; i++){
            if(!(req & (1LL<<i))){
                if(k & (1LL<<j)) req = req | (1LL << i);
                j++;
            }
        }
        return req;
    }
    long long minEnd(int n, int x) {
        int cnt = __builtin_popcount(x);
        long long l = largest(x);
        int rem = (l+1) - cnt;
        int cnt_rem = (1<<rem);
        n--;
        int start = n % cnt_rem;
        long long start_num = find_start(x, start);
        int req = n - start;
        l++;
        while(req > 0){
            req -= cnt_rem;
            start += cnt_rem;
            start_num = start_num + (1LL<<l);
        }
        return start_num;
    }
};