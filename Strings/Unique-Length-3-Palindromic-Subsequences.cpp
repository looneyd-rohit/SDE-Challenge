// Leetcode 1930

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> ranges(26, {-1, n});
        for(int i=0; i<n; i++){
            int ch = s[i] - 'a';
            if(ranges[ch].first == -1) ranges[ch].first = i;
        }
        for(int i=n-1; i>=0; i--){
            int ch = s[i] - 'a';
            if(ranges[ch].second == n) ranges[ch].second = i;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            int f = ranges[i].first, ss = ranges[i].second;
            if(f==-1 || ss==n) continue;
            unordered_set<char> us;
            for(int ind=f+1; ind<ss; ind++) us.insert(s[ind]);
            ans += us.size();
        }
        return ans;
    }
};