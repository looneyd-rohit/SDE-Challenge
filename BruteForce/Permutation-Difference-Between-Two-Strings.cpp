// Leetcode 3146

// Approach: simple brute force
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.length(), m = t.length();
        unordered_map<int, int> ump;
        for(int i=0; i<m; i++) ump[t[i]] = i;
        int sum = 0;
        for(int i=0; i<n; i++) sum += abs(i - ump[s[i]]);
        return sum;
    }
};