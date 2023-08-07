// Leetcode 17

class Solution {
public:
    void solve(int index, string& digits, vector<string>& letters, string& temp, vector<string>& ans){
        // base case
        if(index >= digits.size()){
            if(temp.size() > 0) ans.push_back(temp);
            return;
        }


        for(auto& ch: letters[digits[index] - '0' - 1]){
            temp.push_back(ch);
            solve(index+1, digits, letters, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp = "";
        vector<string> ans;
        solve(0, digits, letters, temp, ans);
        return ans;
    }
};