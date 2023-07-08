// Q3.

class Solution {
public:
    int solve(int index, string& s, unordered_set<string>& powers){
        // base case
        if(index >= s.length()) return 0;
        
        int ans = 1e9;
        for(int i=index; i<s.length(); i++){
            string temp = s.substr(index, i-index+1);
            if(powers.count(temp)){
                ans = min(ans, 1 + solve(i+1, s, powers));
            }
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<string> v = {"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001"};
        unordered_set<string> powers(begin(v), end(v));
        int ans = solve(0, s, powers);
        if(ans >= 1e9) return -1;
        return ans;
    }
};