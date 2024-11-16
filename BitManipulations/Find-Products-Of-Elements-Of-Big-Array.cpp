// Leetcode 3145

// Approach [IMP] Approach: cyclic property of bits + counting logic + observation
class Solution {
public:
    long long bin_exp(long long a, long long b, long long mod){
        long long res = 1;
        while(b){
            if(b & 1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    unsigned long long f(long long num, int i){
        // returns the count of i-th bit set in range [0...num]
        // based on the cyclic property of bits
        unsigned long long a = (num + 1) / (1LL << (i+1));
        a = a * (1LL << i);
        long long excess = ((num + 1) % (1LL << (i+1))) - (1LL << i);
        return a + max(excess, 0LL);
    }
    unsigned long long g(long long num){
        unsigned long long sum = 0;
        for(int i=0; i<63; i++){
            unsigned long long t = f(num, i);
            sum += t;
        }
        return sum;
    }
    unsigned long long g_bit(long long num){
        unsigned long long sum = 0;
        for(int i=0; i<63; i++){
            unsigned long long t = f(num, i);
            sum += t * i;
        }
        return sum;
    }
    long long binary_search(long long k){
        long long low = 1, high = 1e15;
        while(low <= high){
            long long mid = low + ((high - low) >> 1);
            unsigned long long set_bits = g(mid);
            if(set_bits >= k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        int q = queries.size();
        vector<int> v;
        for(auto& query: queries){
            long long lb = query[0]+1, ub = query[1]+1, mod = query[2];
            long long lb_num = binary_search(lb), ub_num = binary_search(ub);

            unsigned long long diff1 = lb - g(lb_num-1);
            unsigned long long diff2 = ub - g(ub_num-1);

            if(lb_num == ub_num){
                long long c = 0;
                unsigned long long ans = 1;
                for(int i=0; i<63; i++){
                    if(lb_num & (1LL << i)){
                        c++;
                        if(c>=diff1 && c<=diff2){
                            ans = ans * (1LL << i);
                            ans %= mod;
                        }
                    }
                }
                v.push_back(ans);
                continue;
            }

            unsigned long long mid_part_sum = max(0ULL, g_bit(ub_num-1) - g_bit(lb_num));

            unsigned long long mid_part = bin_exp(2, mid_part_sum, mod);

            unsigned long long excess = 1;
            // for left part which is uneven
            int a = 0;
            for(int i=0; i<63; i++){
                if(lb_num & (1LL << i)){
                    a++;
                    if(a >= diff1){
                        excess = excess * (1LL << i);
                        excess %= mod;
                    }
                }
            }
            // for right part which is uneven
            int b = 0;
            for(int i=0; i<63; i++){
                if(ub_num & (1LL << i)){
                    b++;
                    if(b <= diff2){
                        excess = excess * (1LL << i);
                        excess %= mod;
                    }
                }
            }
            unsigned long long ans = (mid_part * excess) % mod;
            v.push_back(ans);
        }
        return v;
    }
};