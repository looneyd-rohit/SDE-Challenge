// Leetcode 140

// Approach: recursion + backtracking
class Solution {
public:
    void solve(int index, int n, string& s, unordered_set<string>& ust, string& temp, vector<string>& ans){
        if(index == n){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<n; i++){
            string str = s.substr(index, i-index+1);
            if(ust.count(str)){
                string new_temp = temp;
                if(new_temp.size() > 0) new_temp.push_back(' ');
                new_temp += str;
                solve(i+1, n, s, ust, new_temp, ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int w = wordDict.size();
        unordered_set<string> ust;
        for(auto& word: wordDict) ust.insert(word);
        string temp = "";
        vector<string> ans;
        solve(0, n, s, ust, temp, ans);
        return ans;
    }
};