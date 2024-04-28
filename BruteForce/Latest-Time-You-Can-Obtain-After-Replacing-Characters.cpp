// Leetcode 3114

// Approach: brute force
class Solution {
public:
    string findLatestTime(string s) {
        int n = s.length();
        if(s[0]=='?'){
            if(s[1]<='1' || s[1]=='?') s[0] = '1';
            else s[0] = '0';
        }
        if(s[1]=='?'){
            if(s[0]=='1') s[1] = '1';
            else s[1] = '9';
        }
        if(s[3]=='?') s[3] = '5';
        if(s[4]=='?') s[4] = '9';
        return s;
    }
};