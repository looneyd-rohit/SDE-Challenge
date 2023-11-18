// Leetcode 1759

class Solution {
public:
    const int M = 1e9+7;
    int countHomogenous(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int cnt = 0;
        while(j<n){
            if(s[j]!=s[i]) i = j;
            // calculate no. of substrings [i...j] ending at j
            cnt += (j-i+1) % M;
            cnt %= M;
            j++;
        }
        return cnt;
    }
};