// Leetcode 459

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int len=n/2; len>=1; len--){
            if(n%len!=0) continue;
            string str = s.substr(0, len);
            int i=len;
            for( ; i+len-1<n; i+=len){
                string str2 = s.substr(i, len);
                if(str!=str2) break;
            }
            if(i==n) return true;
        }
        return false;
    }
};