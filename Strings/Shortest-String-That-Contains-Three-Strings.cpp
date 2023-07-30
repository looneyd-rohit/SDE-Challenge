// Leetcode 2800

class Solution {
public:
    bool find(string& a, string& b){
        int n = a.size(), m = b.size();
        for(int i=m-1, j=n-1; i>=0 && j>=0; i--, j--){
            if(b[i]!=a[j]) return false;
        }
        return true;
    }
    string merge(string a, string& b){
        int n = a.size(), m = b.size();
        if(a.find(b)!=string::npos) return a;    // a contains b
        // else find suffix prefix match
        int ind = -1;
        for(int i=0; i<m; i++){
            if(i+1 > n) break;
            string pref = b.substr(0, i+1);
            if(find(a, pref)){
                ind = i;
            }
        }
        return a + b.substr(ind+1);
    }
    static bool cmp(string& a, string& b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
    string minimumString(string a, string b, string c) {
        // try to merge one string with another to get the min length string such
        // that both are substrings of the combined
        // try all 3! combinations
        vector<string> mergedStrings = {
            merge(merge(a, b), c),
            merge(merge(a, c), b),
            merge(merge(b, a), c),
            merge(merge(b, c), a),
            merge(merge(c, a), b),
            merge(merge(c, b), a),
        };
        sort(begin(mergedStrings), end(mergedStrings), cmp);
        return mergedStrings[0];
    }
};