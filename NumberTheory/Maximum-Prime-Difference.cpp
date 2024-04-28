// Leetcode 3115

// Approach: use sieve to find primes
class Solution {
public:
    void sieve(vector<bool>& p, int k){
        p[0] = p[1] = false;
        for(int i=2; i*i<k; i++){
            if(p[i]){
                for(int j=i*i; j<k; j+=i){
                    p[j] = false;
                }
            }
        }
    }
    int maximumPrimeDifference(vector<int>& A) {
        int n = A.size(), S = 101;
        vector<bool> p(S, true);
        sieve(p, S);
        int a = -1, b = -1;
        for(int i=0; i<n; i++){
            if(p[A[i]]){
                if(a == -1) a = i;
                b = i;
            }
        }
        return (b - a);
    }
};