// Leetcode 205

// Approach 1: two pass
class Solution {
public:
    bool solve(string s, string t){
        int n = s.length(), m = t.length();
        if(n!=m) return false;
        unordered_map<char, char> ump;
        for(int i=0; i<n; i++){
            if(ump.find(s[i])==ump.end()){
                ump[s[i]] = t[i];
            }else if(ump[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return solve(s, t) && solve(t, s);
    }
};

// Approach 2: one pass
class Solution {
public:
    bool solve(string s, string t){
        int n = s.length(), m = t.length();
        if(n!=m) return false;
        unordered_map<char, char> ump1;
        unordered_map<char, char> ump2;
        for(int i=0; i<n; i++){
            if(ump1.find(s[i])!=ump1.end() && ump1[s[i]]!=t[i]) return false;
            if(ump2.find(t[i])!=ump2.end() && ump2[t[i]]!=s[i]) return false;
            ump1[s[i]] = t[i];
            ump2[t[i]] = s[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return solve(s, t);
    }
};