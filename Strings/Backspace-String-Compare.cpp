// Leetcode 844

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length(), m = t.length();
        string s1 = "";
        for(int i=0; i<n; i++){
            if(s[i]=='#'){
                if(!s1.empty()) s1.pop_back();
            }else{
                s1.push_back(s[i]);
            }
        }
        string t1 = "";
        for(int i=0; i<m; i++){
            if(t[i]=='#'){
                if(!t1.empty()) t1.pop_back();
            }else{
                t1.push_back(t[i]);
            }
        }
        return (s1==t1);
    }
};