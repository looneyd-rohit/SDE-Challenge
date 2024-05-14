// Leetcode 397

// Approach 1: brute force + dp
class Solution {
public:
    unordered_map<int, int> dp;
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(dp.find(n)!=dp.end()) return dp[n];
        if(n & 1){
            return dp[n] = 1 + min(integerReplacement(n-1), n==INT_MAX?1+integerReplacement((1LL*n+1)>>1):integerReplacement(n+1));
        }else{
            return dp[n] = 1 + integerReplacement(n/2);
        }
    }
};

// Approach 2: using bit manipulations
class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        long long num = n;
        while(num > 1){
            cout<<num<<endl;
            if(!(num&1)){
                num >>= 1;
            }else if(num==3 || __builtin_popcount(num+1) > __builtin_popcount(num-1)){
                num--;
            }else{
                num++;
            }
            count++;
        }
        return count;
    }
};