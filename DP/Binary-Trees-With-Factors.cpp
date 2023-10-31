// Leetcode 823
// Approach 1: Using DP
class Solution {
public:
    const int M = 1e9+7;
    int dp[(int)1e3+1];
    long long solve(int index, vector<int>& arr, unordered_map<int, int>& hash){
        // base case
        if(index==0){
            return 1;
        }
        
        // dp check
        if(dp[index]!=-1) return dp[index];

        int root = arr[index];
        // taking current element as root find the left and right childs
        long long ans = 1;
        for(int i=0; i<index; i++){
            int lc = arr[i];
            if((root % lc)==0){
                int rc = root / lc;
                if(hash.find(rc)!=hash.end()){
                    // can be taken
                    int rcInd = hash[rc];
                    ans += solve(i, arr, hash) * solve(rcInd, arr, hash);
                    ans %= M;
                }
            }
        }
        return dp[index] = ans % M;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        sort(begin(arr), end(arr));
        unordered_map<int, int> hash;
        for(int i=0; i<n; i++) hash[arr[i]] = i;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            int t = solve(i, arr, hash);
            total += t;
            total %= M;
        }
        return total;
    }
};

// Approach 2: Using Hashmaps Optimization
class Solution {
public:
    const int M = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        unordered_map<int, int> hash;
        for(int i=0; i<n; i++) hash[arr[i]] = 1;
        long long ans = n;
        for(int i=0; i<n; i++){
            int root = arr[i];
            long long cnt = 0;
            for(int j=0; j<i; j++){
                int lc = arr[j];
                if((root%lc)==0){
                    int rc = root/lc;
                    if(hash.find(rc)!=hash.end()){
                        // right child exists
                        cnt += hash[lc] * 1LL * hash[rc];
                        cnt %= M;
                    }
                }
            }
            hash[root] += cnt;
            hash[root] %= M;
            ans += cnt;
            ans %= M;
        }
        return ans;
    }
};