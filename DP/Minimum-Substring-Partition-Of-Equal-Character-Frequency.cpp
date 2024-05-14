// Leetcode 3144

// Approach: simple recursion + dp
class Solution {
public:
    long long store[1001];
    long long dfs(int ind, string& s){
        if(ind == s.length()) return 0;
        
        if(store[ind]!=-1) return store[ind];
        
        long long a = 1e9, maxi = 0;
        unordered_map<char, int> mapa;
        for(int i=ind; i<s.length(); i++){
            mapa[s[i]]++;
            maxi = max(maxi, 1LL*mapa[s[i]]);
            int len = i-ind+1;
            if((i - ind + 1) == (mapa.size() * 1LL * maxi)){
                a = min(a, 1 + dfs(i+1, s));
            }
        }
        return store[ind] = a;
    }
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        memset(store, -1, sizeof(store));
        return (int)dfs(0, s);
    }
};